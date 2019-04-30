hello: main.o
	gcc -o hello main.c

clean:
	rm *.o hello