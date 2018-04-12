#include <stdio.h>
#include <string.h>


void mostrar_prompt(char* cadena);
int parsear_comando(char* cadena, char* arg[]);

/* Muestra un prompt por pantalla
 * Retorna la cadena que haya ingresado el usuario hasta presionar ENTER
 */
void mostrar_prompt(char* cadena) {
	printf ("> ");
	scanf("%[^\n]", cadena);
}


/* Recibe una cadena y la divide en subcadenas
 * tomando como separador el espacio
 * Retorna las subcadenas como un arreglo de cadenas llamado arg
 */
int parsear_comando(char* cadena, char* arg[]) {    
   char *ptrToken;
   char *comando;
   int cont=0;
   
   printf("La cadena es: %s \n", cadena);
          
   ptrToken = strtok(cadena, " "); //obtengo el primer token
   comando = ptrToken;

   while (ptrToken != NULL) {
		arg[cont] = ptrToken;
      printf("Arg[%d]: %s \n",cont, arg[cont]);
		cont++;
		ptrToken = strtok(NULL, " "); //obtengo el siguiente token		
   }
   
   return 0;
}
