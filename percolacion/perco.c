#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"

#define P     64             // 1/2^P, P=16
#define Z     50            // iteraciones
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

  FILE *output = fopen("output.txt", "w");
  if (output == NULL)
  {
      printf("Error opening file!\n");
      exit(1);
  }

  fprintf(output, "###INICIO ITERACIONES###\n##### dimension: %dx%d , iteraciones z: %d #####\n\n",n,n,z);

  for(i=0;i<z;i++)
    {
          srand(time(NULL));
          prob=0.4;
          denominador=2.0;
          pc=prob;
          for(j=0;j<P;j++)
          {
              llenar(red,n,prob); //llena red
              //imprimir(red,n);
              hoshen(red,n); //etiqueta red
              //imprimir(red,n);

              denominador = 2.0*denominador;

              if (percola(red,n))
              {
                printf("percola a proba: %.5f\n",prob);
                pc = prob;
                prob+=(-1.0/denominador);
              }
              else { prob+=(1.0/denominador); }

          }
          fprintf(output, "%.5f\n", pc);
          printf("z: %d",z);
    }

  free(red);
  fclose(output);

  return 0;
}
