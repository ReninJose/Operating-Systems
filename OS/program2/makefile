CC=/usr/bin/g++
CFLAGS=-I.
DEPS=processor.h
OBJ=main.o processor.o

%.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)

build: $(OBJ) $(DEPS)
	$(CC) -o program2 $^ $(CFLAGS)
	mkdir source && mv main.o processor.o source/

run:
	./program2

clean: 
	rm -f program2 && rm -drf sources