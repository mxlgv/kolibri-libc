
KTCC=../linuxtools/kos32-tcc
KPACK = kpack
CFLAGS = -nostdlib -I../include -L../lib ../lib/crt0.o 

BIN=stdio_test.kex

all: $(BIN)

%.kex : %.c
	$(KTCC) $(CFLAGS) $< -o $@
	$(KPACK) $@

clean:
	rm *.kex