Consigna: Debes crear un sistema de monitoreo y visualización utilizando los siguientes componentes:

1) Comportamiento del Tira de Led de NeoPixel (6 LEDs):La tira de  6 LEDs se utilizará para representar la flexión del sensor flexible de la siguiente manera:
Flexión mínima: Los LEDs deben  encenderse e ir encendiendo en orden  incremental hasta el angulo marcado. ( max hasta 45°
LED 0 AL 1)
Flexión media: Los LEDs se deben ir encendiendo en orden incremental   ( 45° a  90° LED 2 AL 3)
Flexión máxima: Todos los LEDs deben encenderse  (completando el anillo de 6 LEDs). ( 90° a 180°
LED 4 AL 5)
En todos los casos, si el sensor retrocede deben ir apagando los led.
 A medida que el sensor detecta mayor o menor flexión, más o meos LEDs del anillo se irán iluminando o apagando uno a uno, de un color fijo:
Verde  ( LED 0 AL 1)
Amarillo (LED 2 AL 3)
Rojo (LED   3 a 5 )
2) Lectura del Sensor Flexible y Monitor Serial:
Debes realizar pruebas de lectura del sensor mediante el Monitor Serial, mostrando en la consola los valores que recibe el Arduino  de la siguiente forma:   "Flex: X 
Angulo: X
N
°Led: X
Color: X "     luego mandar un enter.
Deshabilitar (sin borrar ni comentar) la parte del código para pruebas de sensores luego de realizar las pruebas de valores.

3) Pantalla LCD debe mostrar: 
La lectura actual del sensor flexible en unidades de flexión ( Angulo 0 a 180) en un renglon
En el sefundo renglon El color en que se debe prender (lo mas a la derexha posible)
4) El estado del sistema ( con Botón en segundo plano ) :
Un PushButton debe usarse para encender y apagar el sistema completo. Al presionar el botón (una sola vez), el sistema debe activarse o desactivarse por completo.
Cuando el sistema está apagado, todos los LEDs deben apagarse
5) Entrega por GIT
subir el resuelto y entregar a classroom de forma adecuada.
-tener comentando y ordenado el codigo.

Tips y helpers:
Lectura dato bruto
pasado a angulo
pasado a n° led
  if (led >= n°) { prender n° } else { apagar n° }
encendido   =   negado de encendido.
