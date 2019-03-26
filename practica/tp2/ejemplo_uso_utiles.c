/*
Ejemplo que permite obtener una cadena desde la entrada estándar y parsear su contenido
*/

#include <stdlib.h>
#include "utiles.h"


int main( int argc, char **argsv ){

	int ntokens, ret;
	char buff[TAM_BUFFER];
	char **tokens = NULL;	
	
	while(TRUE){
		
		ret = leer_linea(buff);
		if ( ret == -1 ){
			fputs("Error al leer linea, demasiados caracteres.\n", stderr); 
			continue;
		}

		
		ret = cargar_tokens(buff, &tokens, &ntokens); 
		if ( ret == -1 ){
			fputs("Error al procesar lineas.\n", stderr); 
			continue;
		}

	}

	return EXIT_SUCCESS;
}