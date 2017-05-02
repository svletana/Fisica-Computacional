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
  int    i,j,k,u,n,z,p,*red,*Intensidad,num,intens;
  float  prob,denominador,pc,*probabilidad,promedio;

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
  Intensidad=(int *)malloc(z*sizeof(int));
  probabilidad=(float *)malloc(z*sizeof(int));

  FILE *output = fopen("output.txt","w");
  if(output == NULL)
  {
    fprintf(stderr,"file not found!");
    exit(1);
  }

  float dp = 0.001;
  for(i=0;i<z;i++)
  {
           srand(time(NULL));
	         intens=0;
           prob=0.58+i*dp;
           for (j=0;j<p;j++) {
              num=0;
              llenar(red,n,prob);
              //imprimir(red,n); printf("\n --------- \n");
              hoshen(red,n);
              //imprimir(red,n); printf("\n_________\n\n");

              for(k=0;k<n*n;k++)
              {
                  if(*(clase + k)!=0 && k>0)
                  {
                      //printf("clase:%d,",*(clase + k));
                      u=k;
                  }
              }

		          for(k=1;k<=u;k++)
              {
                  printf("%d | ",*(s + k));
              }



              if (percola(red,n))
              {
		              num=percola(red,n);
                  intens+=s[num];
              }
          }
        	promedio=(float)intens/p;

        	if (promedio!=0){	*(Intensidad + i)=promedio;	}
        	else {*(Intensidad + i)=0;}

          *(probabilidad + i)=prob;
  }


	for(k=0;k<z;k++)
  {
        fprintf(output,"%d",*(Intensidad + k));
        fprintf(output,",");
  }

  fprintf(output, "\n");

  for(k=0;k<z;k++) 
  {
  		fprintf(output,"%f",*(probabilidad + k));
  		fprintf(output,",");
	}




  free(red);
  free(clase);
  free(s);

  return 0;
}
