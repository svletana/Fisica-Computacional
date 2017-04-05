#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define P     1             // 1/2^P, P=16
#define Z     1          // iteraciones
#define N     5             // lado de la red simulada


void  llenar(int *red,int n,float prob); //done
int   hoshen(int *red,int n); //done
int   actualizar(int *red,int *clase,int s,int frag); //done
void  etiqueta_falsa(int *red,int *clase,int s1,int s2,int n); //done
void  corregir_etiqueta(int *red,int *clase,int n);
//int   percola(int *red,int n);
void  imprimir(int *red,int n); //done

int main(int argc,char *argv[])
{
  int    i,j,n,z,*red;
  float  prob,denominador;

  n=N;
  z=Z;

  if (argc==3)
     {
       sscanf(argv[1],"%d",&n);
       sscanf(argv[2],"%d",&z);
     }

  red=(int *)malloc(n*n*sizeof(int));



  for(i=0;i<z;i++)
    {
      prob=0.5;
      denominador=2.0;

      srand(time(NULL));

      for(j=0;j<P;j++)
        {
          llenar(red,n,prob); //llena red
          imprimir(red,n);
          hoshen(red,n); //etiqueta red
          imprimir(red,n);

          denominador=2.0*denominador; //kesesto
/*
          if (percola(red,n))
             prob+=(-1.0/denominador);
          else prob+=(1.0/denominador);
*/
        }
    }

  free(red);

  return 0;
}



int hoshen(int *red,int n)
{
  /*
    Esta funcion implementa el algoritmo de Hoshen-Kopelman.
    Recibe el puntero que apunta a la red y asigna etiquetas
    a cada fragmento de red.
  */

  int i,j,k,s1,s2,frag;
  int *clase;

  frag=0;

  clase=(int *)malloc(n*n*sizeof(int)); //alocatea el vector de etiquetas en memoria

  for(k=0;k<n*n;k++) *(clase+k)=frag; //...y la llena de ceros

  // primer elemento de la red

  s1=0;
  frag=2; //arrancvoid  corregir_etiqueta(int *red,int *clase,int n)amos con la etiqueta '2'
  if (*red) frag=actualizar(red,clase,s1,frag);

  // primera fila de la red

  for(i=1;i<n;i++)
    {
      if (*(red+i))
         {
           s1=*(red+i-1);  //esto agarra el elemento anterior
           frag=actualizar(red+i,clase,s1,frag);
         }
    }


  // el resto de las filas

  for(i=n;i<n*n;i=i+n) //esto avanza de a n, ojo
    {

      // primer elemento de cada fila

      if (*(red+i))
         {
           s1=*(red+i-n); //toma el elemento que esta arriba de donde estamos
           frag=actualizar(red+i,clase,s1,frag);
         }

      for(j=1;j<n;j++)
        	if (*(red+i+j))
        	  {
        	    s1=*(red+i+j-1);
              s2=*(red+i+j-n);

        	    if (s1*s2>0)
        	      {
        		        etiqueta_falsa(red+i+j,clase,s1,s2,n);
        	      }
        	    else
        	      {
                  if (s1!=0) frag=actualizar(red+i+j,clase,s1,frag);
        	        else       frag=actualizar(red+i+j,clase,s2,frag);
        	      }
        	  }
            }


  corregir_etiqueta(red,clase,n);

  free(clase);

  return 0;
}


void  llenar(int *red,int n,float prob)
{
	/*
	Esta funcion llena una red con una dada probabilidad.
	Recibe el puntero a la red, el tamaño de la misma y la probabilidad de ocupar un sitio.
	*/
	int i,j;
	for(i=0;i<n;i++) //row index
	{
		for(j=0;j<n;j++) //column index
		{
		  double r =  ((double)rand())/RAND_MAX; //generate random number between 0 and 1
		  if(r<prob) { *(red + i*n + j) = 1; }
		  else { *(red + i*n + j) = 0; }
		}
	}
}


int   actualizar(int *red,int *clase,int s,int frag)
{
	/*
	Actualiza etiqueta segun el caso en el que estemos.
	*/
  if(s==0 && *red)
  {
    *red = frag;
    //clase = ?
    frag++;
  }
  else
  {
    *red = s;
    //clase = ?
  }
  return frag;
}

void  etiqueta_falsa(int *red,int *clase,int s1,int s2, int n)
{
  if(s1<s2) { *red = s1; *(red - n) = s1; }
  else { *red = s2; *(red - 1) = s2;}
  //clase = ?
}

void  corregir_etiqueta(int *red,int *clase,int n)
{

}

void  imprimir(int *red,int n)
{
  int i,j;
  for(i=0;i<n;i=i+1)
  {
    for(j=0;j<n;j=j+1)
    {
      printf("%d ",red[i*n + j]);
    }
    printf("\n");
  }
  printf("\n------\n");
}
