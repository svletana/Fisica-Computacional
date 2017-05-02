# Ejercicio 2

Se calculó la masa del cluster infinito con _perco.c_. Para las redes mencionadas en el primer argumento del ejecutable, se corrieron las siguientes realizaciones:
./out 4 50 20 _(./out n z p)_
./out 16 50 20
./out 32 50 20
./out 64 50 20
./out 128 50 20

La probabilidad inicial fue 0.01 y el paso fue 1/z+0.01. En este caso z fue 50 y p 20. Las iteraciones en p se corresponden a determinar 20 veces la masa del tamaño del cluster percolante, para luego determinar la masa del cluster percolante como el promedio de esas veinte mediciones.
Luego, se realizó un barrido mas fino para la zona crítica:
./out 4 40 20
./out 16 40 20
./out 32 40 20
./out 64 40 20
./out 128 40 20

El z=40 en este caso y la probabilidad inicial 0.58. El paso fue de 0.001.

Para calcular la intensidad, se dividio cada tira de datos por L^2, donde L es el lado de la red correspondiente (n).
Los gráficos se realizaron con Matlab (la extensión de los archivos es _.m_). Se realizó un ajuste en la zona creciente, desde 0.58 hasta 0.62. 
Se ajustó la curva siguiendo una ley de potencias, obteniendo de esta manera el coeficiente crítico beta.
