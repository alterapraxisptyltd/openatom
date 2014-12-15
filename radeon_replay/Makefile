SRCS=radeon_replay.c \
	edid.c \
	radeon_dp_aux.c \
	radeon_util.c \
	radeon_tests.c \
	radeon_util.c \
	refined_replay.c \
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

