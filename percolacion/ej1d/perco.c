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


  FILE *output = fopen("out1d.txt","w");
  if(output == NULL)
  {
    fprintf(stderr,"file not found!");
    exit(1);
  }

  //float promedio = 0; // ejercicio 1a
  
  for(i=0;i<z;i++)
    {
          srand(time(NULL));
          prob=0.59; // para ejercicio 1d, uso pc encontrada para cada tamaño de red. para el 1a y 1c pongo 0.55
          denominador=2.0;
          //pc=0; //ejercicio 1a

          for(j=0;j<p;j++)
          {

              llenar(red,n,prob);
              //imprimir(red,n); printf("\n --------- \n");
              hoshen(red,n);
              //imprimir(red,n); printf("\n_________\n\n");

              /* ---EJERCICIO 1(d)--- */
              fprintf(output, "%.6f\n", prob);
              //esto es para descartar los valores de etiqueta que no se ocuparon, ya que de entrada el array es de n*n
              w=0;
              for(k=2;k<n*n;k++)
              {
                  if(*(clase + k)>=2)
                  {
                    w++;//esto seria la cantidad de veces que encontro una etiqueta valida
                    u=k; //indice de la ultima etiqueta valida
                  }
              }
              ss = (int *)malloc(w*sizeof(int));
              l=0;
              for(k=2;k<=u;k++)
              {
                  if(*(s+k)!=0) { *(ss+l) = *(s+k); l++; }
              }
              for(k=0;k<w;k++) fprintf(output, "%d,", *(ss+k));
              fprintf(output, "\n\n"); //delimita cada tira de datos corresp. a una probabilidad
              /* --- --- */

              denominador = 2.0*denominador;

              ph = percola(red,n);
              if (ph)
              {
                //pc = prob;
                prob+=(-1.0/denominador);
              }

              else { prob+=(1.0/denominador);}
          }
          //promedio+=pc; //ejercicio 1(a)
          //fprintf(output, "%.6f,", pc);
    }

  //fprintf(output, "\n\npromedio: %.6f",promedio/z);
  fclose(output);

  free(red);
  free(clase);
  free(s);
  return 0;
}
