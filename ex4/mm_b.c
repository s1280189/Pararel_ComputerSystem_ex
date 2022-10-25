#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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



float rand_float()
{
  return (float)rand()/((float)RAND_MAX+1);
}

void MMA_d(double* a, double* b, double* c, int b, int id)
{
   int i,j,k;
  for(i=0;i<b;i++){
    for(j=0;j<b;j++){
      for(k=0;k<b;k++){
	c[i*b+j]= c[i*b+j]+a[i*b+k]*b[k*b+j];
      }
    }
  }	
}

void MMA_f(float* a, float* b, float* c, int b, int id)
{
  int i,j,k;
  for(i=0;i<b;i++){
    for(j=0;j<b;j++){
      for(k=0;k<b;k++){
	c[i*b+j]= c[i*b+j]+a[i*b+k]*b[k*b+j];
      }
    }
  }	
}

double L1_normd(double *a, int n){
  int i;
  double result=0;
  for(i=0;i<n;i++){
    result=result+sqrt(a[i]*a[i]);
  }

  return result;
}

double L1_normf(float *a, int n){
   int i;
  double result=0;
  for(i=0;i<n;i++){
    result=result+sqrt((double)a[i]*(double)a[i]);
  }

  return result;
}

int main(){

  int n;
  double *a_d, *b_d, *c_d;
  float  *a_f, *b_f, *c_f;
  double elapsedTime;
  int i,j,k;
  double en,st;
  int i_d, j_d, k_d;

  
  
  printf("input N=id = (8, 16, 32, 64, 128, 256, 512, 1024, 2048)\n->");
  scanf("%d", &n);

  a_d=(double *)malloc(sizeof(double)* n*n);
  b_d=(double *)malloc(sizeof(double)* n*n);
  c_d=(double *)malloc(sizeof(double)*n*n);
  a_f=(float *)malloc(sizeof(float)* n*n);
  b_f=(float *)malloc(sizeof(float)* n*n);
  c_f=(float *)malloc(sizeof(float)* n*n);
  
  
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a_d[i*n+j]=rand_double();
      b_d[i*n+j]=rand_double();
      c_d[i*n+j]=0;
      a_f[i*n+j]=rand_float();
      b_f[i*n+j]=rand_float();
      c_f[i*n+j]=0;
    }
  }//initialize

  const int b=4;
  double MA[b][b], MB[b][b], MC[b][b];
  
   //double---------------------------
  st=e_time();
  for(i=0;i<n;i+=b){
    for(j=0;j<n;j+=b){

      	for(i_d=i; i_d<i+b; i_d++){
	  for(j_d=j; j_d<j+b; j_d++){
	    MC[i_d][j_d]=0;
	  }
	}
      
      
      for(k=0;k<n;k+=b){
	
	for(i_d=i; i_d<i+b; i_d++){
	  for(j_d=j; j_d<j+b; j_d++){
	    for(k_d=k; k_d<k+b; k_d++){
	      MA[i_d][k_d]=a_d[i_d*n+k_d];
	      MB[k_d][j_d]=b_d[k_d*n+j_d];
	    }
	  }
	}

	MMA_d(MA, MB, MC, nb, nb);
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("double , elapsed time: %f\n",elapsedTime);
  elapsedTime=2*pow((double)n, 3.0)/(elapsedTime)/1.0e6;
  printf("-> %f MFLOPS\n",elapsedTime);
  //float-------------------------------
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c_f[i*n+j]=c_f[i*n+j]+a_f[i*n+k]*b_f[k*n+j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("float , elapsed time: %f\n", elapsedTime);
  elapsedTime =  2*pow((double)n, 3.0)/(elapsedTime)/1.0e6;
  printf("-> %f MFLOPS\n", elapsedTime);

  free(a_d);
  free(b_d);
  free(c_d);
  free(a_f);
  free(b_f);
  free(c_f);

  return 0;
}
