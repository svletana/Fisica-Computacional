#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"


int *masa(int *red, int *clase, int n)
{
  /*Crea el vector de masas de clusters "s"*/
  int i,j;
  
  for(i=0;i<n*n;i++) *(s+i) = 0;


  /*START LOOP*/
  for (i=0;i<n*n;i++)
  {
  	for (j=0;j<n*n;j++)
    {
  		if (clase[i]==red[j] && clase[i]>1) {s[i]+=1;}
  	}
	}
  /*END LOOP*/

  /*
  fprintf(output,"vector s\n");
  for(i=0;i<n*n;i++)
  {
    fprintf(output, "%d,",*(s+i));
  }
  fprintf(output,"\nvector clase\n");
  for(i=0;i<n*n;i++)
  {
    fprintf(output, "%d,",*(clase+i));
  }
  fprintf(output,"\n");

  fclose(output);
  */
  return s;
}
