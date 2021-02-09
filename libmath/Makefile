# Math build for kolibri-libc
# Makefile was written by maxcodehack

CC = ../bin/kos32-tcc

SRC = acosh.c acos.s asinh.c asin.s atan2.s atanh.c atan.s \
	ceil.s cosh.c cos.s exp.s fabs.s floor.s fmod.s frexp.c \
	hypot.c ldexp.c log.s modfl.s modf.s pow10.s pow2.s pow.s sinh.c \
	sin.s sqrt.s tanh.c tan.s libtcc1.c

OBJECTS = $(patsubst %.s, %.o, $(patsubst %.c, %.o, $(SRC)))

all: $(OBJECTS)
	ar rcs libm.a $(OBJECTS)
	mv libm.a ../bin/lib/
	rm $(OBJECTS)

%.o : %.c
	$(CC) -c -m32 -nostdinc -ffreestanding -I../source/include -o $@ $<

%.o : %.s
	cpp -nostdinc -fno-pie -I. $*.s -o $*.sx $(CSFLAGS)
	as --32 $*.sx -o $*.o
	rm $*.sx
