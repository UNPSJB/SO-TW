usem_threads: usem_threads.o
	gcc usem_threads.o -o usem_threads -pthread

usem_threads.o: usem_threads.c
	gcc -c usem_threads.c -o usem_threads.o

clean:
	rm usem_threads *.o
