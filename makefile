CC=gcc
CFLAGS=-I. -Wall -Wextra -Werror -g
OBJ=test.o my_malloc.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean: 
	rm *.o test

all: test
	./test
