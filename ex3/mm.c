#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<sys/resource.h>

double e_time(){
  static struct timeval now;
  gettimeofday(&now, NULL);
  return (double)(now.tv_sec + now.tv_usec/1000000.0);
}


double rand_double()
{
  return (double)rand()/((double)RAND_MAX+1);
}



float rand_float()
{
  return (float)rand()/((float)RAND_MAX+1);
}



int main(){

  int n=8;
  double a_d[n][n], b_d[n][n], c_d[n][n];
  float a_f[n][n], b_f[n][n], c_f[n][n];
  double elapsedTime;
  int i,j,k;
  double en,st;
  
  
  printf("input N=id = (8, 16, 32, 64, 128, 256, 512, 1024, 2048)\n");
  scanf("%d", &n);
  
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a_d[i][j]=rand_double();
      b_d[i][j]=rand_double();
      c_d[i][j]=0;
      a_f[i][j]=rand_float();
      b_f[i][j]=rand_float();
      c_f[i][j]=0;
    }
  }//initialize
   //double---------------------------
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c_d[i][j]=c_d[i][j]+a_d[i][k]*b_d[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("double N=8, elapsed time: %f\n",elapsedTime);
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);
  //float-------------------------------
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c_f[i][j]=c_f[i][j]+a_f[i][k]*b_f[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("float N=8, elapsed time: %f\n", elapsedTime);
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);

  return 0;
}
