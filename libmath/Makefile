# Math build for kolibri-libc
# Makefile was written by maxcodehack

SRC = acosh.c acos.s asinh.c asin.s atan2.s atanh.c atan.s \
	ceil.s cosh.c cos.s exp.s fabs.s floor.s fmod.s frexp.c \
	hypot.c ldexp.c log.s modfl.s modf.s pow10.s pow2.s pow.s sinh.c \
	sin.s sqrt.s tanh.c tan.s

OBJECTS = $(patsubst %.s, %.o, $(patsubst %.c, %.o, $(SRC)))

all: $(OBJECTS)
	ar rcs libm.a $(OBJECTS)
	mv libm.a ../bin/lib/
	rm $(OBJECTS)

%.o : %.c
	gcc -c -m32 -nostdinc -ffreestanding -I../source/include -o $@ $<

%.o : %.s
	cpp -nostdinc -I. $*.s -o $*.sx $(CSFLAGS)
	as --32 $*.sx -o $*.o
	rm $*.sx
