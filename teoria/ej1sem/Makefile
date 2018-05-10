all: proc1_sem proc2_sem

proc1_sem: proc1_sem.o
	gcc proc1_sem.o -o proc1_sem -pthread

proc1_sem.o: proc1_sem.c
	gcc -c proc1_sem.c -o proc1_sem.o

proc2_sem: proc2_sem.o
	gcc proc2_sem.o -o proc2_sem -pthread

proc2_sem.o: proc2_sem.c
	gcc -c proc2_sem.c -o proc2_sem.o

clean:
	rm proc1_sem proc2_sem *.o
