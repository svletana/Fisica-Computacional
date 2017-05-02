# Ejercicio 1(b)

El archivo _perco.c_ toma los parámetros _n_, _z_ y _p_.

Se realizaron dos tipos de realizaciones. Para todas las redes (4,16,32,64,128) primero se ejecutó el código de la siguiente manera:
./out 4 100 27000
./out 16 100 10000
./out 32 100 10000
./out 64 100 10000
./out 128 100 10000
donde 100 corresponden a las iteraciones en z, y 10000-27000 a las iteraciones en p. La probabilidad inicial fue 0 en este caso, y el paso en probabilidades fue de 0.01.

Luego, se realizó un barrido más fino en la zona cercana al punto crítico.
Comenzando con una probabilidad en 0.56, y un paso de 0.001 se ejecutó de la siguiente forma:
./out 4 50 10000
./out 16 50 10000
./out 32 50 10000
./out 64 50 10000
./out 128 50 10000

Esto produce la tabla de resultados _output.txt_, donde la primera columna es la probabilidad de ocupacion de un nodo y la segunda columna es la probabilidad de la red de percolar.

Estos datos se graficaron y se tomó la probabilidad crítica como la probabilidad donde la altura de la curva está a 0.5
