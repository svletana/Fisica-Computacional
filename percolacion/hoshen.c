#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"

int hoshen(int *red,int n)
{
  /*
    Esta funcion implementa el algoritmo de Hoshen-Kopelman.
    Recibe el puntero que apunta a la red y asigna etiquetas
    a cada fragmento de red.
  */

  int i,j,k,s1,s2,frag;
  //int *clase,*s;

  frag=0;

  //clase=(int *)malloc(n*n*sizeof(int));

  for(k=0;k<n*n;k++) *(clase+k)=frag;
  *(clase + 1) = 1;

  // primer elemento de la red

  s1=0;
  frag=2;
  if (*red) frag=actualizar(red,clase,s1,frag);

  // primera fila de la red

  for(i=1;i<n;i++)
    {
      if (*(red+i))
         {
           s1=*(red+i-1);  //agarra el elemento anterior
           frag=actualizar(red+i,clase,s1,frag);
         }
    }


  // el resto de las filas

  for(i=n;i<n*n;i=i+n) //avanza de a n
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
  s = masa(red,clase,n);


  return 0;
}



int   actualizar(int *red,int *clase,int s,int frag)
{
	/*
	Actualiza etiqueta segun el caso en el que estemos.
	*/
  if(s==0 && *red)
  {
    *red = frag;
    *(clase + frag) = frag;
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
  while(*(clase+s1)<0) { s1 = -*(clase+s1); }
  while(*(clase+s2)<0) { s2 = -*(clase+s2); }

  if(s2>s1)
  {
    *red = s1;
    *(clase + s2) = -s1;
    *(clase + s1) = s1;
  }
  else if(s1>s2)
  {
    *red = s2;
    *(clase + s1) = -s2;
    *(clase + s2) = s2;
  }
  else
  {
    actualizar(red,clase,s1,s1);
  }
}

void  corregir_etiqueta(int *red,int *clase,int n)
{
  int k,h,p;
  for(k=0;k<n*n;k++)
  {
    h = *(red + k);
    if(h>1)
    {
      p = *(clase + h);
      if(p<0)
      {
        while(p<0) { p = *(clase - p); }
        *(red + k) = p;
      }
    }
  }
}
