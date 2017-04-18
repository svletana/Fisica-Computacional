#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"


int masa(int *red, int *clase, int n)
{
  int i,j,*s;
  s=(int *)malloc(n*n*sizeof(int));

  FILE *etiquetas = fopen("claseYs.txt","w");

  for(i=0;i<n*n;i++) *(s+i) = 0;

  for (i=0;i<n*n;i++) {
	for (j=0;j<n*n;j++) {
		if (clase[i]==red[j] && clase[i]>1) {s[i]+=1;}
		}
	}

  fprintf(etiquetas,"vector s\n");
  for(i=0;i<n*n;i++) 
  {
    fprintf(etiquetas, "%d,",*(s+i));
  }
  fprintf(etiquetas,"\nvector clase\n");
  for(i=0;i<n*n;i++) 
  {
    fprintf(etiquetas, "%d,",*(clase+i));
  }
 
  fclose(etiquetas);

  return 0;
}
