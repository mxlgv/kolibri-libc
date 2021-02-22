AR = ar -rcs
INCLUDE = include
LIB_DIR = ../bin/lib
LIBNAME = $(LIB_DIR)/libc.a
CFLAGS = -I$(INCLUDE) -m32 -nostdinc -nostdlib -DGNUC -Os -fno-common -fno-builtin -fno-leading-underscore -fno-pie
DIRS :=  string stdlib stdio sys math ctype

cfiles := $(foreach dir,$(DIRS),$(patsubst %.c, %.o, $(wildcard $(dir)/*.c)))
asmfiles := $(foreach dir,$(DIRS),$(patsubst %.s, %.o, $(wildcard $(dir)/*.s)))
.PHONY: clean all

ifdef windir
cfiles := $(subst /,\,$(cfiles))
asmfiles := $(subst /,\,$(asmfiles))
LIB_DIR := $(subst /,\,$(LIB_DIR))
LIBNAME := $(subst /,\,$(LIBNAME))
RM = del /F /Q
MKDIR_P = md
else
RM = rm -rf
MKDIR_P = mkdir -p
endif

all: $(cfiles) $(asmfiles) $(LIB_DIR) $(LIBNAME)
	fasm crt/crt0.asm ../bin/lib/crt0.o

$(LIBNAME): $(cfiles) $(asmfiles)
	$(AR) $(LIBNAME) $^

$(LIB_DIR):
	$(MKDIR_P) $(LIB_DIR)

$(asmfiles):
	$(CPP) -nostdinc -Imath $*.s > $*.sx
	$(AS) --32 $*.sx -o $*.o
	$(RM) $*.sx

clean:
	$(RM) $(cfiles) $(asmfiles)
	$(RM) $(LIBNAME)

test:
	make -C ../test -f Makefile.tcc
	kex ../test/test
	
