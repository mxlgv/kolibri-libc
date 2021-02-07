NAME=test

KTCC= ../bin/kos32-tcc
KPACK= kpack

SRC=test.c
INCLUDE = -I ../source/include

all:
	$(KTCC) $(INCLUDE) $(NAME).c -o $(NAME) -lc
	$(KPACK) $(NAME)

clean:
	rm $(NAME).o
