#!/bin/make

ARUBA_SRCS= \
	dp_aux.c

ARUBA_OBJS = $(sort ${ARUBA_SRCS:.c=.o})

ARUBA_TARGET=libaruba.a


$(ARUBA_TARGET): $(ARUBA_OBJS)
	$(AR) -rcs $@ $^

clean-aruba:
	-$(RM) $(ARUBA_OBJS) $(ARUBA_TARGET)
