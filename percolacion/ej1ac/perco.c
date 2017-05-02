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
  int    i,j,k,l,u,w,n,z,p,ph,*red,*ss;  /* puede ser que algunas variables definidas terminen sin ser usadas, dependiendo que ejercicio este haciendo */
  float  prob,denominador,pc,dp;

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
    fprintf(stderr,"file not found!");
    exit(1);
  }

  float promedio = 0;

  for(i=0;i<z;i++)
    {
          srand(time(NULL));
          prob=0.55;
          denominador=2.0;
          pc=0;

          for(j=0;j<p;j++)
          {

              llenar(red,n,prob);
              //imprimir(red,n); printf("\n --------- \n");
              hoshen(red,n);
              //imprimir(red,n); printf("\n_________\n\n");

              denominador = 2.0*denominador;

              ph = percola(red,n);
              if (ph)
              {
                pc = prob;
                prob+=(-1.0/denominador);
              }

              else { prob+=(1.0/denominador);}
          }
          promedio+=pc;
          fprintf(output, "%.6f,", pc);
    }

  fprintf(output, "\n\npromedio: %.6f",promedio/z);
  fclose(output);

  free(red);
  free(clase);
  free(s);
  return 0;
}
