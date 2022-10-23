#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<math.h>

double e_time(){
  static struct timeval now;
  gettimeofday(&now, NULL);
  return (double)(now.tv_sec + now.tv_usec/1000000.0);
}


double rand_double()
{
  return (double)rand()/((double)RAND_MAX+1);
}






int main(){

  int n;
  double *a_d, *b_d, *c_d;
  float  *a_f, *b_f, *c_f;
  double elapsedTime;
  int i,j,k;
  double en,st;
  
  
  printf("input N=id = (8, 16, 32, 64, 128, 256, 512, 1024, 2048)\n->");
  scanf("%d", &n);

  a_d=(double *)malloc(sizeof(double)* n*n);
  b_d=(double *)malloc(sizeof(double)* n*n);
  c_d=(double *)malloc(sizeof(double)*n*n);
  
  
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a_d[i*n+j]=rand_double();
      b_d[i*n+j]=rand_double();
      c_d[i*n+j]=0;
    }
  }//initialize
   //double---------------------------
  st=e_time();
  for(j=0;j<n;j++){
    for(k=0;k<n;k++){
      for(i=0;i<n;i++){
	c_d[i*n+j]=c_d[i*n+j]+a_d[i*n+k]*b_d[k*n+j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("double , elapsed time: %f\n",elapsedTime);
  elapsedTime=2*pow((double)n, 3.0)/(elapsedTime)/1.0e6;
  printf("-> %f MFLOPS\n",elapsedTime);
  //float-------------------------------

  free(a_d);
  free(b_d);
  free(c_d);
  return 0;
}
