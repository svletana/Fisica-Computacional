#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"

void  llenar(int *red,int n,float prob)
{
	/*
	Esta funcion llena una red con una dada probabilidad.
	Recibe el puntero a la red, el tamaño de la misma y la probabilidad de ocupar un sitio.
	*/
	int i,j;

	for(i=0;i<n;i++) //row index
	{
		for(j=0;j<n;j++) //column index
		{
		  double r =  ((double)rand())/RAND_MAX; //generate random number between 0 and 1
		  if(r<prob) { *(red + i*n + j) = 1; }
		  else { *(red + i*n + j) = 0; }
		}
	}
}
