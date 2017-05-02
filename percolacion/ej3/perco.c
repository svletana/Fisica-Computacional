#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define P     10000             // 1/2^P, P=16
#define Z     1            // iteraciones
#define N     128             // lado de la red simulada

/*VARIABLES GLOBALES*/
int *clase;
int *s;

#include "functions.h"

int main(int argc,char *argv[])
{
  int    i,j,k,u,n,z,p,*red,*Intensidad,num,sn;
  float  prob,denominador,pc,*probabilidad,ssn,*snum;

  n=N;
  z=Z;
  p=P;

  if (argc==3)
     {
       sscanf(argv[1],"%d",&n);
       sscanf(argv[2],"%d",&z);
       sscanf(argv[3],"%d",&p);
     }

  red=(int *)malloc(n*n*sizeof(int));
  clase = (int *)malloc(n*n*sizeof(int));
  s = (int *)malloc(n*n*sizeof(int));
  Intensidad=(int *)malloc(n*n*sizeof(int));
  probabilidad=(float *)malloc(n*n*sizeof(float));
  snum=(float *)malloc(n*n*sizeof(float));

  FILE *output = fopen("output.txt","w");
  if(output == NULL)
  {
    fprintf(stderr,"file not found!");
    exit(1);
  }


  float dp = 0.01;

  for(i=0;i<z;i++) {
	sn=0;
	prob=0.595+i*dp;
	fprintf(output,"%f",prob);

	for (j=0;j<p;j++) {

	      srand(time(NULL));
              llenar(red,n,prob);
              //imprimir(red,n); printf("\n --------- \n");
              hoshen(red,n);
              //imprimir(red,n); printf("\n_________\n\n");

              if (percola(red,n))
              {
		              num=percola(red,n);
                  fprintf(output, "PERCOLA, etiqueta: %d\n",percola(red,n));
              }

              else { fprintf(output, "NO PERCOLA\n"); }

		printf("%d\n",s[num]);
		sn+=s[num];

    }

	 ssn=sn/p;
	 printf("%f",ssn);

 }

  free(red);
  free(clase);
  free(s);

  return 0;
}
