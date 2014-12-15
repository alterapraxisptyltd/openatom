TARGET=radeon_replay
all: $(TARGET)

include aruba/Makefile.inc

SRCS=radeon_replay.c \
	coreboot_glue.c \
	drm_dp_helper.c \
	edid.c \
	linux_glue.c \
	radeon_util.c \
	radeon_tests.c \
	radeon_util.c \
	refined_replay.c \
	vga_io.c \
	vga_replay.c

OBJS = $(sort ${SRCS:.c=.o})

MODULES = aruba
LIBS=$(sort ${MODULES:%=lib%.a})
VPATH=$(MODULES)

CFLAGS += -Wall -I$(shell pwd)
REMOTE := mrnuke@192.168.1.141:/home/mrnuke
SCP := scp

$(TARGET): $(OBJS) $(LIBS)
	$(CC) $(LIBS) $^ -o $@

clean: clean-aruba
	-$(RM) $(OBJS) $(TARGET)

install:
	$(SCP) $(TARGET) $(REMOTE)

%/lib%.a:
	$(MAKE) -C %
