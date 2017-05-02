# Ejercicios 1 (a) y (c)

El archivo _perco.c_ corre con el resto de los archivos que aparecen en _Makefile_, compilarlos juntos. El ejecutable _out_ toma los parámetros _n_, _z_ y _p_.
Genera un archivo _output.txt_ que tiene, para cada una de las _z_ iteraciones, una tira de datos de probabilidades críticas obtenidas y el promedio de las mismas.
Use _z=1_ y _p=5000_, o sea que la probabilidad crítica promedio esta hecha a partir de 5000 valores de Pc obtenidos, y a partir de esa tira de datos se saca la dispersión también.

El script _punto1ac.py_ simplemente lee el archivo _output.txt_ y devuelve promedio y dispersión. Los resultados para cada tamaño de red están en _promediosydisp.txt_

El script _fiteo.py_ se usó para hacer un ajuste de cuadrados mínimos a Pc(L) vs dispersión y obtener la probabilidad crítica correspondiente a la red infinita.
