#!/bin/bash
# Una solución muy básica al ejercicio 9 de la Práctica 1.
# Este script devuelve la latitud y la longitud de una ciudad de Chubut.
# La ciudad se busca por nombre según el parámetro ingresado al invocar el script.
#
# En este caso se utilizó el servicio brindado por:
#    https://nominatim.openstreetmap.org/
#
# Como verán al inspeccionar el código, es muy fácil extender esta solución para que
# busque ciudades o lugares en todo el mundo.
# De todas formas, habría que procesar mucho mejor las respuestas, y contemplar una
# búsqueda sin respuesta.
#
# Deben contar con conexión a Internet para probarlo.
# La respuesta que el script entrega entre paréntesis es la que pueden copiar y pegar
# en Google Maps para corroborar dicha respuesta.
#
# Sistemas Operativos 2019 - UNPSJB, Trelew

if [ $# -eq 0 -o $# -gt 1 ];then
	echo "Uso: $0 <nombre>|-h"
	echo "<nombre>: Nombre de ciudad o lugar a buscar."
	echo "-h: Muestra información y ayuda de uso."
	echo "Sistemas Operativos 2019 - UNPSJB, Trelew"
	exit 1
fi

if [ "$1" == "-h" ];then
	echo "$0:"
	echo "Uso: $0 <nombre>|-h"
	echo "<nombre>: Nombre de ciudad o lugar a buscar."
	echo "-h: Muestra información y ayuda de uso."
	echo "Devuelve las coordenadas, latitud y longitud, de una ciudad."
	echo "Sistemas Operativos 2019 - UNPSJB, Trelew"
	exit 1
fi

res1=$(curl -s "https://nominatim.openstreetmap.org/search/$1%20chubut%20argentina/?format=json&limit=1")

res2=$(echo $res1 | grep -o "\"display_name\":\"[^\"]\{1,\}\"")
echo $res2 | sed "s/\"//g" | sed "s/display_name://g"

res3=$(echo $res1 | grep -o "\"lat\":\"[^\"]\{1,\}\",\"lon\":\"[^\"]\{1,\}\"")
echo $res3 | sed "s/\"//g"
echo "("$res3")" | sed "s/\"//g" | sed "s/lat://g" | sed "s/lon://g" | sed "s/,/ /g" 

