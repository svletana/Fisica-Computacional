#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]) {
  double threshold = strtod(argv[1], NULL); //probability of site being occuppied
  int n = atoi(argv[2]);
  int netw[n][n];
  srand(time(NULL));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) {

      double r =  ((double)rand())/RAND_MAX; //generate random number between 0 and 1
      
      if(r<threshold) {
        netw[i][j] = 1;
      }
      else {
        netw[i][j] = 0;
      }
      printf("%d ",netw[i][j]);
    }
    printf("\n");

  }

  return 0;
}
