TARGET=radeon_replay
all: $(TARGET)

include aruba/Makefile.inc

SRCS=radeon_replay.c \
	coreboot_glue.c \
	drm_dp_helper.c \
	edid.c \
	linux_glue.c \
	radeon_util.c \
	vga_io.c \
	vga_replay.c

OBJS = $(sort ${SRCS:.c=.o})

MODULES = aruba
LIBS=$(sort ${MODULES:%=lib%.a})
VPATH=$(MODULES)

CFLAGS += -Wall -I$(shell pwd)

$(TARGET): $(OBJS) $(LIBS)
	$(CC) $(LIBS) $^ -o $@

clean: clean-aruba
	-$(RM) $(OBJS) $(TARGET)

%/lib%.a:
	$(MAKE) -C %
