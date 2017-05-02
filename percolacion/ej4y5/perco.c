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
  int    i,j,a,d,f,g,n,z,p,*red,*ss;//,ph;  /* puede ser que algunas variables definidas terminen sin ser usadas, dependiendo que ejercicio este haciendo */
  float  prob;//,denominador,pc;

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

  FILE *salida = fopen("salida.txt","w");
  if(salida == NULL)
  {
    fprintf(stderr,"file not found!");
    exit(1);
  }


  float p0 = 0.001;
  float dp = (double)(1.0-p0)/z;
  for(i=0;i<z;i++)
    {
          srand(time(NULL));
          prob=p0+i*dp;
          fprintf(salida, "%ffin", prob);

          for(j=0;j<p;j++)
          {

              llenar(red,n,prob);
              //imprimir(red,n); printf("\n --------- \n");
              hoshen(red,n);
              //imprimir(red,n); printf("\n_________\n");

              //esto es para descartar los valores de etiqueta que no se ocuparon, ya que de entrada el array es de n*n
              g=0;
              f=0;
              for(a=2;a<n*n;a++)
              {
                  if(*(clase + a)>=2)
                  {
                    g++;//esto seria la cantidad de veces que encontro una etiqueta valida
                    f=a; //indice de la ultima etiqueta valida encontrada
                  }
              }


              ss = (int *)malloc(g*sizeof(int));
              for(a=0;a<g;a++) *(ss+a)=0;
              if(f!=0)
              {
                d=0;
                for(a=2;a<=f;a++)
                {
                    if(*(s+a)!=0) { *(ss+d) = *(s+a); d++; } //el vector ss es la parte del vector s que necesito, descartando lo demas
                }

                for(a=0;a<g;a++) { fprintf(salida, "%d,", *(ss+a)); /*printf("%d,", *(ss+a));*/ }
              }
              else { fprintf(salida, "%d", 0); }
              fprintf(salida, "\n"); //printf("\n");

          }
          fprintf(salida,"return"); //'return' delimita cada tira de datos corresp. a una misma probabilidad
    }

  fclose(salida);

  free(red);
  free(clase);
  free(s);
  return 0;
}
