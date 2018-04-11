#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int cant = 0;
void manejador(int num) {
   printf("Recibí señal\n");
   cant++;
   if (cant == 3) {
      printf("Finalizo mi ejecución\n");
      exit(1);
   }
}
int main(void) {
   signal(2, manejador);
   while (1);
}
