INCLUDE = include

LIBNAME = ../tools/lib/libc.a
CC = ../tools/kos32-tcc
CFLAGS = -I$(INCLUDE) -m32 -nostdinc -nostdlib -DGNUC
DIRS :=  ksys string

cfiles := $(foreach dir,$(DIRS),$(patsubst %.c, %.o, $(wildcard $(dir)/*.c)))
asmfiles := $(foreach dir,$(DIRS),$(patsubst %.asm, %.o, $(wildcard $(dir)/*.asm)))

.PHONY: clean all

ifdef windir
doClean = del /F /Q $(subst /,\,$(cfiles)) $(subst /,\,$(asmfiles))
else
doClean = rm $(cfiles) $(asmfiles)
endif

all: $(cfiles) $(asmfiles)
	ar -rcs $(LIBNAME) $^

$(asmfiles):
	fasm $*.asm $*.o

clean:
	$(doClean) 
	rm -f $(LIBNAME)

