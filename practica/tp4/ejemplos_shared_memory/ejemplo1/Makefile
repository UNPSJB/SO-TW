all: a b

a: a.c
	gcc a.c -o a -lrt

b: b.c
	gcc b.c -o b -lrt

clean:
	rm a b *.o
