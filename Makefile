# Makefile for Cross Interleaved Reed Solomon encoder/decoder
#
# (c) Henry Minsky, Universal Access 1991-1996
#

RANLIB = ranlib
AR = ar


VERSION = 1.0
DIRNAME= rscode-$(VERSION)


CC = gcc
# OPTIMIZE_FLAGS = -O69
DEBUG_FLAGS = -g
CFLAGS = -Wall -Wstrict-prototypes  $(OPTIMIZE_FLAGS) $(DEBUG_FLAGS) -I..  -DNPAR=8
LDFLAGS = $(OPTIMIZE_FLAGS) $(DEBUG_FLAGS)

LIB_CSRC = rs.c galois.c berlekamp.c crcgen.c experiment.cc
LIB_HSRC = ecc.h
LIB_OBJS = rs.o galois.o berlekamp.o crcgen.o

TARGET_LIB = libecc.a
TEST_PROGS = example experiment

TARGETS = $(TARGET_LIB) $(TEST_PROGS)

all: $(TARGETS)

$(TARGET_LIB): $(LIB_OBJS)
	$(RM) $@
	$(AR) cq $@ $(LIB_OBJS)
	if [ "$(RANLIB)" ]; then $(RANLIB) $@; fi

example: example.o galois.o berlekamp.o crcgen.o rs.o
	gcc $(CFLAGS) -o example example.o -L. -lecc

experiment: experiment.cc galois.o berlekamp.o crcgen.o rs.o
	g++  $(CFLAGS)  -o experiment experiment.cc -L. -lecc

clean:
	rm -f *.o example libecc.a experiment
	rm -f *~

dist:
	(cd ..; tar -cvf rscode-$(VERSION).tar $(DIRNAME))

depend:
	makedepend $(SRCS)

# DO NOT DELETE THIS LINE -- make depend depends on it.

