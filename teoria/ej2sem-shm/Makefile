all: prod_shm cons_shm

prod_shm: prod_shm.c prod_cons.h
	gcc -o prod_shm prod_shm.c -lrt -pthread

cons_shm: cons_shm.c prod_cons.h
	gcc -o cons_shm cons_shm.c -lrt -pthread

clean:
	rm prod_shm cons_shm
