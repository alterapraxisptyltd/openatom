TARGET=radeon_replay
all: $(TARGET)

include aruba/Makefile.inc
include external_encoders/Makefile.inc

SRCS=radeon_replay.c \
	atomfake_inseminator.c \
	coreboot_glue.c \
	drm_dp_helper.c \
	edid.c \
	linux_glue.c \
	radeon_dp_encoder.c \
	radeon_util.c \
	radeon_tests.c \
	radeon_util.c \
	refined_replay.c \
	vga_io.c \
	vga_gilded.c \
	aruba_coreboot_only.c \
	aruba_coreboot_asic_init.c \
	coreboot_libre_radeon.c

OBJS = $(sort ${SRCS:.c=.o})

MODULES = aruba external_encoders
LIBS=$(sort ${MODULES:%=lib%.a})
VPATH=$(MODULES)

CFLAGS += -Wall -g3 -I$(shell pwd)
REMOTE := mrnuke@192.168.1.141:/home/mrnuke
SCP := scp

$(TARGET): $(OBJS) $(LIBS)
	$(CC) $(LIBS) $^ -o $@

clean: clean-aruba clean-external_encoders
	-$(RM) $(OBJS) $(TARGET)

install:
	$(SCP) $(TARGET) $(REMOTE)

%/lib%.a:
	$(MAKE) -C %
