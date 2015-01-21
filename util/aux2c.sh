#!/bin/bash

# Decode AUX channel transactions from a replay log
# This works for channel 0 FIFO only
#

hex=0-9,a-f
aux_ctl=0x6200
fifo_ctl=0x6204
aux_ctl2=0x620c
status=0x6210
fifo=0x6218
pad_ctl=0x6530

# We don't care if it's a _sync read or not
#sed '/radeon_read/,/radeon_write/{s/_sync/_fuck/g}' $1 |
sed -r '/radeon_(read|write)/s/_sync//g' $1 |
# Prune scratch registers accesses (usually at 0x9fxxxxxx)
egrep -v "radeon_(read|write)(_sync|)\(0x9f[$hex]{6}" |

# Prune reads from FIFO control registers
sed -r "/radeon_read\($fifo_ctl\);/d" |

# Kill accesses to pad control register; They're uninteresting
sed -r "/radeon_(read|write)\($pad_ctl/d" |

# Accesses to there registers tell us almost nothing interesting
sed -r "/radeon_(read|write)\($aux_ctl/d" |
sed -r "/radeon_(read|write)\($aux_ctl2/d" |

# This IO indicates we're about to read the FIFO
sed -r "s/radeon_write\($fifo, 0x80000001/fifo_switch\(/g" |
# FIFO writes are fairly straightforward
sed -r "s/radeon_write\($fifo, 0x0000([$hex]{2})00/fifo_write\(0x\1/g" |
# Now the same for FIFO reads
sed -r "s/radeon_read\($fifo\); \/\* 00[$hex]{2}([$hex]{2})01/fifo_read\(\); \/\* \1/g" |
# Detect where we start seeding the FIFO
sed -r "s/radeon_write\($fifo, 0x8000([$hex])[$hex]00/fifo_start\(0x\1/g" |

# Make reads to status register more obvious
sed -r "s/radeon_read\($status/get_status\(/g" |

tr '\n' '\r' |

# Now extract the transaction size on succesive writes to to FIFO control
sed -r "s/radeon_write\($fifo_ctl, 0x[$hex]{8}\);\r\tradeon_write\($fifo_ctl, 0x[$hex]{2}([$hex]{2})[$hex]{4}/tx_size\(0x\1/g" |
# Extract address from subsequent FIFO writes
sed -r "/fifo_start\(/s/0x([$hex])\);\r\tfifo_write\(0x([$hex]{2})\);\r\tfifo_write\(0x([$hex]{2})/0x\1, 0x\2\3/g" |
# Include the tx size in the argument list of fifo_start
sed -r "s/tx_size\((0x[$hex]{2})\);\r\tfifo_start\((0x[$hex]), (0x[$hex]*)/fifo_start\(\2, \1, \3/g" |
# Explicitate each transactions
sed -r "s/fifo_start\(0x9, /aux_read\(/g" |
sed -r "s/fifo_start\(0x8, /aux_write\(/g" |
sed -r "s/fifo_start\(0x1, /i2c_read\(/g" |
sed -r "s/fifo_start\(0x5, /i2c_read_mot\(/g" |
sed -r "s/fifo_start\(0x0, /i2c_write\(/g" |
sed -r "s/fifo_start\(0x4, /i2c_write_mot\(/g" |

# Prune delay-wait loops
sed -r "s/\r\tget_status[^\r]*\r\tradeon_delay[^\r]*//g" |
# Remove repetitive get_status calls. Those are wait loops.
sed -r "s/(\r\tget_status[^\r]*)*/\1/g" |

# This sequence indicates we're reading the reply field
sed -r "s/fifo_switch[^\r]*\r\tfifo_read/get_reply/g" |

tr '\r' '\n' |

# Remaining writes to FIFO CTL are just leftovers of a mask operation
sed -r "/radeon_write\($fifo_ctl/d" |

# Remove the following line if you need to see status reads
sed -r "/get_status\(/d" |
sed -r "/get_reply[^$hex]*00/d" |

# Back to more complicated business
tr '\n' '\r' |

# Concatenate AUX writes into one line
sed -r "s/aux_write\(0x08, ([$hex, x]*)[^\r]*\r\tfifo_write\((0x[$hex]{2})/aux_write\(0x07, \1, \2/g" |
sed -r "s/aux_write\(0x07, ([$hex, x]*)[^\r]*\r\tfifo_write\((0x[$hex]{2})/aux_write\(0x06, \1, \2/g" |
sed -r "s/aux_write\(0x06, ([$hex, x]*)[^\r]*\r\tfifo_write\((0x[$hex]{2})/aux_write\(0x05, \1, \2/g" |
sed -r "s/aux_write\(0x05, ([$hex, x]*)[^\r]*\r\tfifo_write\((0x[$hex]{2})/aux_write\(0x04, \1, \2/g" |
sed -r "s/aux_write\(0x04, ([$hex, x]*)[^\r]*\r\tfifo_write\((0x[$hex]{2})/aux_write\(0x03, \1, \2/g" |

# The fifo_write after an aux_read is the read size argument
sed -r "s/aux_read\(0x04, ([$hex, x]*)[^\r]*\r\tfifo_write\((0x[$hex]{2})/aux_read\(\1, \2/g" |
# Concatenate received data onto one line
sed -r "/aux_read\(0x[$hex]{4}, /s/0x07\);([^\r]*)\r\tfifo_read\(\); ([^\r]*)/0x06);\1\2/g" |
sed -r "/aux_read\(0x[$hex]{4}, /s/0x06\);([^\r]*)\r\tfifo_read\(\); ([^\r]*)/0x05);\1\2/g" |
sed -r "/aux_read\(0x[$hex]{4}, /s/0x05\);([^\r]*)\r\tfifo_read\(\); ([^\r]*)/0x04);\1\2/g" |
sed -r "/aux_read\(0x[$hex]{4}, /s/0x04\);([^\r]*)\r\tfifo_read\(\); ([^\r]*)/0x03);\1\2/g" |
sed -r "/aux_read\(0x[$hex]{4}, /s/0x03\);([^\r]*)\r\tfifo_read\(\); ([^\r]*)/0x02);\1\2/g" |
sed -r "/aux_read\(0x[$hex]{4}, /s/0x02\);([^\r]*)\r\tfifo_read\(\); ([^\r]*)/0x01);\1\2/g" |
sed -r "/aux_read\(0x[$hex]{4}, /s/0x01\);([^\r]*)\r\tfifo_read\(\); ([^\r]*)/0x00);\1\2/g" |
# Concatenate the last byte and kill the size argument for aux reads, and
sed -r "/aux_read\(0x[$hex]{4}/s/, 0x00\);([^\r]*)\r\tfifo_read\(\); ([^\r]*)/); \1\2/g" |

tr '\r' '\n' |

# Now kill the size argument
sed -r "/aux_write\(/s/0x03, //g" |
# And the size byte
sed -r "/aux_write\(/s/(0x[$hex]{4}), 0x[$hex]{2}/\1/g" |

# Remaining FIFO accesses are just for alignment. Kill them
sed -r "/fifo_(read|write)\(/d"
