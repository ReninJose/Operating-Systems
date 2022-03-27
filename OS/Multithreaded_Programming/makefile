CC=/usr/bin/g++
CFLAGS=-pthread

build: main.cpp prod_cons_MT.cpp prod_cons_MT.h
	$(CC) -o thread main.cpp prod_cons_MT.cpp prod_cons_MT.h $(CFLAGS)

run:
	./thread $(s) $(p) $(c)

clean: 
	rm -f thread 

debug:
	make clean
	make build
	make run 
