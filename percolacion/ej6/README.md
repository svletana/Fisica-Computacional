# Ejercicio 6

**usar el archivo percola.c que esta en esta carpeta para este ejercicio, es distinto al anterior. El archivo functions.h tambien es distinto.**

Para calcular m2, se realizó un programa en Octave, encargado de ejecutar el programa anexo en C, y de calcular n_s. Se realizaró el programa para una red de 128, con z=60, barriendo un rango de probabilidades desde 0.5 a 0.7.

Cada m2 se calculó 100 veces, y luego se realizó el promedio correspondiente sobre los datos. Se calculó s con el programa en C, y se armó n_s en octave. Luego, se quitaron del vector s los clusters percolantes, así como también los números de clusters que se repetían, puesto que la cantidad de clsuters de determinado tamaño quedan registrados en el vector n_s. Se elevó cada componente de s al cuadrado y se lo multiplicó sobre su correspondiente valor de n_s.
Luego, de realizar el procedimiento antes mencionado para cada s, se sumaron los resultados obtenidos. Esto se realizó para cada una de las 60 probabilidades mencionadas.

Obtenido el gráfico correspondiente, se tomaron 7 zonas de ambos lados del punto crítico para realizar los correpondientes ajustes lineales para obtener el coeficiente crítico gamma. Los ajustes se realizaron con elprograma Matlab.

Datos obtenidos:
Distancia a pc	---	Gamma izquierdo	---	Gamma derecho
0.066			2			7.391
0.0627			1.854
0.0594						6.24
0.0561			1.823
0.0495						9.679
0.0429			1.864			1.653
0.033			1.449			3.50
0.0264			1.178			1.718
0.00165			0.166			0.8959

El archivo de Octave usado para calcular el exponente _D_ es _proc.m_
