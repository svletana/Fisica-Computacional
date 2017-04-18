#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"

#define P     1             // 1/2^P, P=16
#define Z     1            // iteraciones
#define N     5             // lado de la red simulada

int main(int argc,char *argv[])
{
  int    i,j,n,z,p,*red;
  float  prob,denominador,pc;

  n=N;
  z=Z;
  p=P;

  if (argc==4)
     {
       sscanf(argv[1],"%d",&n);
       sscanf(argv[2],"%d",&z);
       sscanf(argv[3],"%d",&p);
     }

  red=(int *)malloc(n*n*sizeof(int));
/*
  FILE *output = fopen("output.txt", "w");
  if (output == NULL)
  {
      printf("Error opening file!\n");
      exit(1);
  }

  fprintf(output, "###INICIO ITERACIONES###\n##### dimension: %dx%d , iteraciones z: %d , P = %d #####\n\n",n,n,z,p);
*/
  float promedio = 0;
  dp = 0.001
  for(i=0;i<z;i++) //MODIFICAR COMO ESCRIBIMOS A UN ARCHIVO
    {
          srand(time(NULL));
          prob=0.4+i*dp;
          denominador=2.0;
          pc=prob;
          for(j=0;j<P;j++) //sacarlo para el punto 2
          {
              llenar(red,n,prob); //llena red
              imprimir(red,n);
              hoshen(red,n); //etiqueta red, corre funcion masa y me da s y clase
              imprimir(red,n);

              denominador = 2.0*denominador;
		/* //solo quiero que etiqueta percola, este loop no
              if (percola(red,n))
              {
                //printf("percola a proba: %.5f\n",prob);
                pc = prob;
                prob+=(-1.0/denominador);
              }
              else { prob+=(1.0/denominador); }
		*/
          }
          promedio+=pc;
          //fprintf(output, "%.5f\n", pc);
          if (i%100==0) { printf("iteracion actual: %d\n pc: %.5f\n",i,pc); }
    }

  //printf("\npromedio: %.5f\n",promedio/z);
  //fprintf(output,"\npromedio: %.5f\n",promedio/z);

  free(red);
  //fclose(output);

  return 0;
}
