KTCC= ../bin/kos32-tcc
KPACK= kpack

SRC=$(NAME).c
INCLUDE = -I ../source/include

.PHONY: all

all: $(NAME)

$(NAME): $(SRC)
	$(KTCC) $(INCLUDE) $(SRC) -o $(NAME) -lc -lm 
	$(KPACK) $(NAME)

clean:
	rm $(NAME).o $(NAME)
