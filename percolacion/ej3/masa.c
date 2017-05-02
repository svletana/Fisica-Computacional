#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"


int *masa(int *red, int *clase, int n)
{
  /*Crea el vector de masas de clusters "s"*/
  int i,j;
  
  for(i=0;i<n*n;i++) *(s+i) = 0;

  for (i=0;i<n*n;i++)
  {
  	for (j=0;j<n*n;j++)
    {
  		if (clase[i]==red[j] && clase[i]>1) {s[i]+=1;}
  	}
	}

  return s;
}
