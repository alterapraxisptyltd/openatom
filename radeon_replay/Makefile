SRCS=radeon_replay.c \
	atomfake_inseminator.c \
	edid.c \
	radeon_dp_aux.c \
	radeon_dp_encoder.c \
	radeon_util.c \
	radeon_tests.c \
	radeon_util.c \
	refined_replay.c \
	vga_io.c \
	vga_simply_fy.c

OBJS = $(sort ${SRCS:.c=.o})

CFLAGS += -Wall -g3
REMOTE := mrnuke@192.168.1.141:/home/mrnuke
SCP := scp

TARGET=radeon_replay

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

clean:
	-$(RM) $(OBJS) $(TARGET)

install:
	$(SCP) $(TARGET) $(REMOTE)
