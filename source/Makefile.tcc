INCLUDE = include

LIB_DIR = ../bin/lib
LIBNAME = $(LIB_DIR)/libc.a
CC = ../bin/kos32-tcc
CFLAGS = -I$(INCLUDE) -m32 -nostdinc -nostdlib -DGNUC
DIRS :=  ksys string stdlib

cfiles := $(foreach dir,$(DIRS),$(patsubst %.c, %.o, $(wildcard $(dir)/*.c)))
asmfiles := $(foreach dir,$(DIRS),$(patsubst %.asm, %.o, $(wildcard $(dir)/*.asm)))

.PHONY: clean all

ifdef windir
doClean = del /F /Q $(subst /,\,$(cfiles)) $(subst /,\,$(asmfiles))
else
doClean = rm $(cfiles) $(asmfiles)
endif

all: $(cfiles) $(asmfiles)
	mkdir -p $(LIB_DIR) 
	ar -rcs $(LIBNAME) $^

$(asmfiles):
	fasm $*.asm $*.o

clean:
	$(doClean)

test:
	make -C ../test -f Makefile.tcc
	kex ../test/test
	
