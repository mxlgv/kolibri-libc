
KTCC=../linuxtools/kos32-tcc
KPACK = kpack
CFLAGS = -I../include 
LDFLAGS =  -nostdlib -L../lib ../lib/crt0.o

BIN= stdio_test.kex \
basic_gui.kex \
http_tcp_demo.kex \
math_test.kex \
string_test.kex


all: $(BIN)
	
%.kex : %.c
	$(KTCC) $(CFLAGS) $(LDFLAGS) $< -o $@ -lc.obj
	$(KPACK) --nologo $@

clean:
	rm *.kex
