INCLUDE = include

LIBNAME = libc.a
CC = ../tools/kos32-tcc
CFLAGS = -I$(INCLUDE) -m32 -nostdinc -nostdlib -DGNUC
DIRS :=  ksys

cfiles := $(foreach dir,$(DIRS),$(patsubst %.c, %.o, $(wildcard $(dir)/*.c)))

.PHONY: clean all

ifdef windir
doClean = del /F /Q $(subst /,\,$(cfiles))
else
doClean = rm -f $(cfiles)
endif

all: $(cfiles) $(asmfiles)
	ar -rcs $(LIBNAME) $^

clean:
	$(doClean) 

