#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"

#define P     1             // 1/2^P, P=16
#define Z     1            // iteraciones
#define N     4             // lado de la red simulada

int *clase;
int *s;

int main(int argc,char *argv[])
{


  int    i,j,n,z,p,*red;
  float  prob,sipercola,probpercolar;

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

  FILE *output = fopen("output.txt", "w");
  if (output == NULL)
  {
      fprintf(stderr,"Error opening file!\n");
      exit(1);
  }

  //float promedio = 0;
    float dp=0.001;

    for(i=0;i<z;i++)
    {

      	  prob=0.56+dp*i;
      	  fprintf(output, "%.5f,", prob);
      	  sipercola=0;

          for(j=0;j<p;j++)
          {

	            srand(time(NULL));
              llenar(red,n,prob); //llena red
              imprimir(red,n);

              hoshen(red,n); //etiqueta red
              imprimir(red,n);


		            if (percola(red,n))
             	 {
		                sipercola+=1.0; // cantidad de veces que percola el sistema para una probabilidad dada.
              	}

	  }
    printf("%f\n",sipercola);
    probpercolar=sipercola/p; //Probabilidad de que la red percole a una probabilidad dada.
    fprintf(output, "%.10f\n", probpercolar);
    printf("%f\n",probpercolar);
  }

  //free(red);
  fclose(output);

  return 0;
}
