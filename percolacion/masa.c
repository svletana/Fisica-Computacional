#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"

//no parece funcionar bien si hay un solo cluster, o sea una sola etiqueta, pero es muy poco probable que eso pase creo...

int masa(int *red, int *clase, int n)
{
  int i,j,k,q,*masas, *labels;

  labels = (int *)malloc(0.5*n*n*sizeof(int));
  for(i=0;i<0.5*n*n;i++) *(labels + i) = -1;

  j = 0;

  for(i=1;i<n*n;i++)
  {
    if(*(clase + i)>1)
    {
      *(labels + i - 1) = *(clase + i); //label 'i' en el lugar i!!
      //printf("label array: %d\n",*(labels + i - 1)); //debug
      j++;
    }
  }

  //for(i=0;i<0.5*n*n;i++) printf("cosa: %d\n", *(labels + i));;

  //printf("counter: %d\n", j); //debug

  masas = (int *)malloc(j*sizeof(int));

  for(i=0;i<0.5*n*n;i++)
  {
    q = *(labels + i);
    if(q<0) pass;
    else {
      for(k=0;k<n*n;k++)
      {
        if(*(red + k)==q)
        {
          //contar
        }
      }
    }
  }

}
