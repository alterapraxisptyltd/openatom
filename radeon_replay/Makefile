SRCS=radeon_replay.c \
	radeon_dp_aux.c \
	radeon_util.c \
	vga_io.c \
	vga_replay.c

OBJS = $(sort ${SRCS:.c=.o})

TARGET=radeon_replay

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

clean:
	-$(RM) $(OBJS) $(TARGET)

