#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define P     1             // 1/2^P, P=16
#define Z     1            // iteraciones
#define N     5             // lado de la red simulada

/*VARIABLES GLOBALES*/
int *clase;
int *s;

#include "functions.h"

int main(int argc,char *argv[])
{
  int    i,j,k,n,z,p,*red;
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
  clase = (int *)malloc(n*n*sizeof(int));
  s = (int *)malloc(n*n*sizeof(int));

  FILE *output = fopen("output.txt","w");
  if(output == NULL)
  {
    printf("file not found!");
    exit(1);
  }

  fprintf(output, "dimensiones red : %dx%d - Z : %d - P : %d\n\n",n,n,z,p);

  float promedio = 0;
  dp = 0.001
  for(i=0;i<z;i++) //MODIFICAR COMO ESCRIBIMOS A UN ARCHIVO
    {
          srand(time(NULL));
          prob=0.58/*+i*dp*/;
          denominador=2.0;
          pc=0;
          for(j=0;j<P;j++)
          {
              llenar(red,n,prob); //llena red
              imprimir(red,n);
              hoshen(red,n); //etiqueta red, corre funcion masa y me da s y clase
              imprimir(red,n);

              fprintf(output, "probabilidad:%.6f\n", prob);

              fprintf(output, "---VECTOR CLASE---\n");
              for(k=0;k<n*n;k++)
              {
                  fprintf(output,"%d | ",*(clase + k));
              }
              fprintf(output, "\n---VECTOR S---\n");
              for(k=0;k<n*n;k++)
              {
                  fprintf(output,"%d | ",*(s + k));
              }
              fprintf(output, "\n");

              denominador = 2.0*denominador;

              if (percola(red,n))
              {
                //printf("percola a proba: %.5f\n",prob);
                pc = prob;
                fprintf(output, "PERCOLA, etiqueta: %d\n probabilidad critica: %.6f\n",percola(red,n),pc);
                prob+=(-1.0/denominador);
              }

              else { fprintf(output, "NO PERCOLA\n"); prob+=(1.0/denominador); }
          }
          fprintf(output, "\n---FIN---\n\n");
          promedio+=pc;
          if (i%100==0) { printf("iteracion actual: %d\n pc: %.5f\n",i,pc); }
    }

  fprintf(output, "\npromedio: %.6f\n",promedio/z);
  free(red);
  free(clase);
  free(s);
  return 0;
}
