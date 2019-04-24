Sistemas Operativos - UNPSJB
Instrucciones para ejecución del código servidor

En los archivos adjuntos hay un pequeño programa Servidor que interactúa
con un cliente telnet
Debes establecer qué hacen.

Para ejecutar los programas en entorno linux, hay que seguir los 
siguientes pasos:


1. Asegurarse que en el archivo /etc/hosts hay una linea en la que aparece 
el nombre "localhost" y la direccion IP 127.0.0.1. Normalmente asi sera.

2. Asegurarse que se encuentre instalado el programa telnet. Para 
verificarlo ejecutar por linea de comandos:
$ telnet
Debe aparecer:

$ telnet> 

De no hallarse instalado, instalarlo con:
$sudo apt-get install telnetd

3. Copiar todo el código fuente en un directorio de linux.

4. En el directorio donde hemos copiado los archivos, compilar con: 

$ make

Se generara un servidor

Desde una ventana, arrancar primero el servidor

$ ./servidor

Desde otras, arrancar clientes telnet:

$ telnet localhost 8888
Recordar que el servidor escucha en el puerto 8888
