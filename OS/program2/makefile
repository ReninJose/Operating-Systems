CC=/usr/bin/g++
CFLAGS=-I.
DEPS=process.h
OBJ=main.o process.o

%.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)

build: $(OBJ) $(DEPS)
	$(CC) -o program2 $^ $(CFLAGS)
	mkdir source && mv main.o process.o source/

run:
	./program2 $(PROCESS)

clean: 
	rm -f program2 && rm -drf source

debug:
	make clean
	make build
	make run $(PROCESS)