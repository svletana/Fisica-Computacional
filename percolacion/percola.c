#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"

int percola(int *red, int n) //falta percolacion entre izq y der
{

    int i,j,a,b,q;
    q=0;

    for(i=0;i<n;i++)
    {
      a = red[i];
      for(j=n*(n-1);j<n*n;j++)
      {
        b=red[j];
        if(a==b && a!=0)
        {
           //printf("perco: %2.2d\n\n\n",a);
           if(a!=q) { q=a;}
        }
      }
    }
    return q;
}
