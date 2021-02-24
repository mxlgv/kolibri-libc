KTCC= ../bin/kos32-tcc
KPACK= kpack

SRC=$(NAME).c
CFLAGS = -I ../source/include -D_DYNAMIC -stack=1048576  # set stack size 1Mb

.PHONY: all

all: $(NAME)

$(NAME): $(SRC)
	$(KTCC) $(CFLAGS) $(SRC) -o $(NAME) 
	$(KPACK) $(NAME)

clean:
	rm $(NAME).o $(NAME)
