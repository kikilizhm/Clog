Clog: main.o Clog.o
	gcc -o Clog main.c Clog.c

clean:
	rm *.o Clog