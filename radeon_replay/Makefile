SRCS=radeon_replay.c \
	aruba_dp_aux.c \
	edid.c \
	linux_glue.c \
	radeon_util.c \
	vga_io.c \
	vga_replay.c

OBJS = $(sort ${SRCS:.c=.o})

CFLAGS += -Wall

TARGET=radeon_replay

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

clean:
	-$(RM) $(OBJS) $(TARGET)

