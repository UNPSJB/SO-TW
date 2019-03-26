#include <stdio.h>
#include <string.h>

#define TAM_BUFFER 300+1
#define STDIN 0
#define STDOUT 1
#define TRUE 1
#define FALSE 0

/************************************************************/
//PROTOTIPOS DE LAS FUNCIONES											*/
/************************************************************/
void mostrar_prompt(char* cadena);
int leer_linea(char buff[TAM_BUFFER]);
int parsear_comando(char *cadena, char *arg[]);
int cargar_tokens(char *linea, char ***tokens, int *ntokens);



/************************************************************/
/*CUERPOS DE FUNCIONES													*/
/************************************************************/
/* Muestra un prompt por pantalla
 * Retorna la cadena que haya ingresado el usuario hasta 
 * presionar ENTER
 */
void mostrar_prompt(char* cadena) {
	printf ("> ");
	scanf("%[^\n]", cadena);
}

/************************************************************/
/*
  Lee de entrada estandar una linea de texto terminada
  en \n y guarda el resultado en buff desde la posicion 0
  como un string terminado en \0.
  No guarda el salto de linea.
  Retorna la cantidad de caracteres leidos o -1 si da error
*/
int leer_linea(char buff[TAM_BUFFER]){

	int cont;
	memset(buff, 0, TAM_BUFFER*sizeof(char));
	
	mostrar_prompt(buff);
	while( getchar() != '\n' );

	buff[TAM_BUFFER] = '\0';
	cont = strlen(buff);
	return ( cont == TAM_BUFFER )? -1 : cont;
}

/************************************************************/
/* Recibe una cadena y la divide en subcadenas
 * tomando como separador el espacio
 * Retorna las subcadenas como un arreglo llamado arg
 */
int parsear_comando(char *cadena, char *arg[]){
	char *ptrToken;
	int cont=0;

	printf("La cadena es %s \n", cadena);

	ptrToken = strtok(cadena, " ");
	
	while (ptrToken != NULL) {
		arg[cont] = ptrToken;
		printf("Arg[%d]: %s \n", cont, arg[cont]);
		cont++;
		ptrToken = strtok(NULL, " ");
	}
	
	return cont;
}

/************************************************************/
/*
  Parsea los tokens descriptos en el string linea y retorna
  un array de strings en *tokens y la cantidad de tokens
  encontrados en *ntokens.
  Retorna -1 si se produce algun error.
  El array se retorna como puntero a región de memoria dinámica.
*/
int cargar_tokens(char *linea, char ***tokens, int *ntokens){
	
	if ( ( (*tokens) = malloc(strlen(linea) * sizeof(char**)) ) ){
		
		*ntokens = parsear_comando(linea, *tokens);
		
		(*tokens) = realloc( (*tokens), (*ntokens) * sizeof(char **) );
		
		return *ntokens;
	}
	else
		return -1;
}