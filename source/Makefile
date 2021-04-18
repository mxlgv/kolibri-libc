CC=kos32-gcc

KPACK=kpack
FASM=fasm 

CFLAGS =  -c -nostdinc -I../include -DGNUC -D_NOT_FUNC_POINT -Os -fno-common -fno-builtin -fno-leading-underscore -fno-pie

SRC=libc.c
LIB=../lib/libc.obj

all:
	$(MAKE) -C ../linuxtools/src
	../linuxtools/ExportGen symbols.txt exports/exports.c
	$(FASM) crt/crt0.asm ../lib/crt0.o
	$(CC) $(CFLAGS) $(SRC) -o $(LIB)
	$(KPACK) $(LIB)
	../linuxtools/LoaderGen symbols.txt ../loader
	../linuxtools/LoaderBuild ../loader
install:
	cp -f ../lib/libc.obj ~/.kex/root/RD/1/LIB

clean:
	rm ../lib/libc.obj
