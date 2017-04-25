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
  int    i,j,k,u,n,z,p,ph,*red;
  float  prob,denominador,pc,pp;

  n=N;
  z=Z;
  p=P;

  if (argc==5)
     {
       sscanf(argv[1],"%d",&n);
       sscanf(argv[2],"%d",&z);
       sscanf(argv[3],"%d",&p);
       sscanf(argv[4],"%f",&pp);
     }

  red=(int *)malloc(n*n*sizeof(int));
  clase = (int *)malloc(n*n*sizeof(int));
  s = (int *)malloc(n*n*sizeof(int));

/*
  FILE *output = fopen("output.txt","w");
  if(output == NULL)
  {
    printf("file not found!");
    exit(1);
  }

  fprintf(output, "dimensiones red : %dx%d - Z : %d - P : %d\n\n",n,n,z,p);
*/
  float promedio = 0;

  //float dp = (double)1/z;
  for(i=0;i<z;i++)
    {
          srand(time(NULL));

          prob=pp;
          denominador=2.0;
          pc=0;

          for(j=0;j<p;j++)
          {

              llenar(red,n,prob);
              //imprimir(red,n); printf("\n --------- \n");
              hoshen(red,n);
              //imprimir(red,n); printf("\n_________\n\n");
              /*
              fprintf(output, "probabilidad:%.6f\n", prob);
              fprintf(output, "---VECTOR CLASE---\n");
              */

              for(k=0;k<n*n;k++)
              {
                  if(*(clase + k)!=0 && k>0)
                  {
                    printf("%d,",*(clase + k));
                    u=k;
                  }
              }
              printf("\n\n");
              /*fprintf(output, "\n---VECTOR S---\n");*/
              for(k=1;k<=u;k++)
              {
                  printf("%d,",*(s + k));
              }

              denominador = 2.0*denominador;

              ph = percola(red,n);
              if (ph)
              {
                //printf("percola, p = %.6f\n", prob);
                //pc = prob;
                //fprintf(output, "PERCOLA, etiqueta: %d\n",percola(red,n));
                prob+=(-1.0/denominador);
              }

              else { /*fprintf(output, "NO PERCOLA\n");*/ prob+=(1.0/denominador); }
          }
          //fprintf(output, "\n---FIN---\n\n");
          //if (i%100==0) { printf("iteracion actual: %d\n",i); } //esto es util si tenemos z muy grande, para saber por donde va
          //promedio+=pc;
          //printf("%.6f,",pc);
    }

  //fprintf(output, "\npromedio: %.6f\n",promedio/z);
  //printf("\n\n%.6f", promedio/z);
  //printf("%dFIN", ph);
  //printf("%f", pp);
  free(red);
  free(clase);
  free(s);
  return 0;
}
