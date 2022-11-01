#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

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

void MMA_d(double* a, double* b, double* c, int d, int id)
{
   int i,j,k;
  for(i=0;i<d;i++){
    for(j=0;j<d;j++){
      for(k=0;k<d;k++){
	c[i*d+j]= c[i*d+j]+a[i*d+k]*b[k*d+j];
      }
    }
  }	
}

void MMA_f(float* a, float* b, float* c, int d, int id)
{
  int i,j,k;
  for(i=0;i<d;i++){
    for(j=0;j<d;j++){
      for(k=0;k<d;k++){
	c[i*d+j]= c[i*d+j]+a[i*d+k]*b[k*d+j];
      }
    }
  }	
}

double L1_normd(double *a, int n){
  int i;
  double result=0;
  for(i=0;i<n;i++){
    result=result+fabs(a[i]);
  }

  return result;
}

double L1_normf(float *a, int n){
   int i;
  double result=0;
  for(i=0;i<n;i++){
    result=result+(double)fabsf(a[i]);
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
  int mi,mj,mk;

  
  
  printf("input N=id = (32, 64, 128, 256, 512, 1024)\n->");
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

   const int b=4;  //change 2, 4, 8, 16 or 32
 
  
   //double---------------------------

  double *MAd, *MBd, *MCd;

  MAd=(double *)malloc(sizeof(double)* b*b);
  MBd=(double *)malloc(sizeof(double)* b*b);
  MCd=(double *)malloc(sizeof(double)* b*b);
  st=e_time();
  for(i=0;i<n;i+=b){
    for(j=0;j<n;j+=b){

      	for(i_d=i; i_d<i+b; i_d++){
	  for(j_d=j; j_d<j+b; j_d++){
	    for(mi=0;mi<b;mi++){
	      for(mj=0;mj<b;mj++){
		MCd[mi*b+mj]=c_d[i_d*n+j_d];
	      }
	    }
	  }
	}
      
      
      for(k=0;k<n;k+=b){
	
	for(i_d=i; i_d<i+b; i_d++){
	  for(j_d=j; j_d<j+b; j_d++){
	    for(k_d=k; k_d<k+b; k_d++){
	      for(mi=0;mi<b;mi++){
		for(mj=0;mj<b;mj++){
		  for(mk=0;mk<b;mk++){
		    MAd[mi*b+mk]=a_d[i_d*n+k_d];
		    MBd[mk*b+mj]=b_d[k_d*n+j_d];
		  }
		}
	      }
	    }
	  }
	}

	MMA_d(MAd, MBd, MCd, b, b);
      }
    }

    for(i_d=i; i_d<i+b; i_d++){
	  for(j_d=j; j_d<j+b; j_d++){
	    for(mi=0;mi<b;mi++){
	      for(mj=0;mj<b;mj++){
		c_d[i_d*n+j_d]=MCd[mi*b+mj];
	      }
	    }
	  }
	}
  }
  en=e_time();
  elapsedTime=en-st;
  printf("double , elapsed time: %f\n",elapsedTime);
  elapsedTime=2*pow((double)n, 3.0)/(elapsedTime)/1.0e6;
  printf("-> %f MFLOPS\n",elapsedTime);

  
  //float-------------------------------
   float *MAf, *MBf, *MCf;

  MAf=(float *)malloc(sizeof(double)* b*b);
  MBf=(float *)malloc(sizeof(double)* b*b);
  MCf=(float *)malloc(sizeof(double)* b*b);
  st=e_time();
  for(i=0;i<n;i+=b){
    for(j=0;j<n;j+=b){

      	for(i_d=i; i_d<i+b; i_d++){
	  for(j_d=j; j_d<j+b; j_d++){
	    for(mi=0;mi<b;mi++){
	      for(mj=0;mj<b;mj++){
		MCf[mi*b+mj]=c_d[i_d*n+j_d];
	      }
	    }
	  }
	}
      
      
      for(k=0;k<n;k+=b){
	
	for(i_d=i; i_d<i+b; i_d++){
	  for(j_d=j; j_d<j+b; j_d++){
	    for(k_d=k; k_d<k+b; k_d++){
	      for(mi=0;mi<b;mi++){
		for(mj=0;mj<b;mj++){
		  for(mk=0;mk<b;mk++){
		    MAf[mi*b+mk]=a_d[i_d*n+k_d];
		    MBf[mk*b+mj]=b_d[k_d*n+j_d];
		  }
		}
	      }
	    }
	  }
	}

	MMA_f(MAf, MBf, MCf, b, b);
      }
    }

    for(i_d=i; i_d<i+b; i_d++){
	  for(j_d=j; j_d<j+b; j_d++){
	    for(mi=0;mi<b;mi++){
	      for(mj=0;mj<b;mj++){
		c_d[i_d*n+j_d]=MCf[mi*b+mj];
	      }
	    }
	  }
	}
  }
  en=e_time();
  elapsedTime=en-st;
  printf("double , elapsed time: %f\n",elapsedTime);
  elapsedTime=2*pow((double)n, 3.0)/(elapsedTime)/1.0e6;
  printf("-> %f MFLOPS\n",elapsedTime);
  //------------------------------------------------------

  
  free(a_d);
  free(b_d);
  free(c_d);
  free(a_f);
  free(b_f);
  free(c_f);
  free(MAd);
  free(MBd);
  free(MCd);
  free(MAf);
  free(MBf);
  free(MCf);

  return 0;
}
