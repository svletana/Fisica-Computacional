#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define P     1             // 1/2^P, P=16
#define Z     10            // iteraciones
#define N     128             // lado de la red simulada

/*VARIABLES GLOBALES*/
int *clase;
int *s;

#include "functions.h"

int main(int argc,char *argv[])
{
  int    i,j,k,l,u,n,z,p,*red, *perco,*Intensidad,num,sn;
  float  prob,denominador,pc,*probabilidad,ssn,*snum;

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
  Intensidad=(int *)malloc(n*n*sizeof(int));
  probabilidad=(float *)malloc(n*n*sizeof(float));
  snum=(float *)malloc(n*n*sizeof(float));
  perco=(int *)malloc(n*n*sizeof(int));

  FILE *output = fopen("output.txt","w");
  if(output == NULL)
  {
    fprintf(stderr,"file not found!");
    exit(1);
  }


  float dp = (0.7-0.5)/z;


  for(i=0;i<z;i++) {
    	prob=0.5+i*dp;
    	for (j=0;j<p;j++)
      {
    	            srand(time(NULL)*z);
                  llenar(red,n,prob);
                  //imprimir(red,n); printf("\n --------- \n");
                  hoshen(red,n);
                  //imprimir(red,n); printf("\n_________\n\n");

    	            for(k=0;k<n*n;k++)
                  {
                      if(*(clase + k)!=0 && k>0)
                      {
                       // printf("clase:%d,",*(clase + k));
                        u=k;
                      }
                  }

                  for(k=1;k<u;k++)
                  {
                      fprintf(output,"%d,",*(s + k));
                  }
    		          for(k=1;k<=u+1;k++)
                  {
                      printf("%d,",*(s + k));
                  }


                  /*if (percola(red,perco,n))
                  {
                    fprintf(output, "PERCOLA, etiqueta: %d\n",percola(red,perco,n));
                  } //quiero saber quien percola así lo excluyo de s

                  else { fprintf(output, "NO PERCOLA\n"); }*/

            		percola(red, perco,n);
            		printf("--");
            		 for (l=0;l<n*n;l++)
            		{
            			printf ("%d,", *(perco + l));
            		}

        }
    	  printf("FIN");
 }

 free(red);
 free(clase);
 free(s);
 return 0;
 
}
