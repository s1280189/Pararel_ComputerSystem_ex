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
  

  //N=8
  
  //double-------------------------------
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a_d[i][j]=rand_double();
      b_d[i][j]=rand_double();
      c_d[i][j]=0;
    }
  }//initialize double a[][],b[][],c[][]
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
  printf("double N=8, elapsed time: %f\n",elapsedtime);
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);
  //float-------------------------------
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a_f[i][j]=rand_float();
      b_f[i][j]=rand_float();
      c_f[i][j]=0;
    }
  }//initialize float a[][],b[][],c[][]
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

  //////////////////////////////////////////////////////////////
  
  //N=16
  n=16;
  //double-------------------------------
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_double();
      b[i][j]=rand_double();
      c[i][j]=0;
    }
  }//initialize double a[][],b[][],c[][]
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st
  printf("double N=16, elapsed time: %f\n",elapsedTime );
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);
  //float-------------------------------
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_float();
      b[i][j]=rand_float();
      c[i][j]=0;
    }
  }//initialize float a[][],b[][],c[][]
   st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("float N=16, elapsed time: %f\n", elapsedTime);
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);

  ///////////////////////////////////////////////////////////////////

  
  //N=32
  n=32;
  //double-------------------------------
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_double();
      b[i][j]=rand_double();
      c[i][j]=0;
    }
  }//initialize double a[][],b[][],c[][]
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("double N=32, elapsed time: %f\n",elapsedTime );
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);
  //float-------------------------------
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_float();
      b[i][j]=rand_float();
      c[i][j]=0;
    }
  }//initialize float a[][],b[][],c[][]
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("float N=32, elapsed time: %f\n", elapsedTime);
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);


  ///////////////////////////////////////////////////////////////
   //N=64
  n=64;
  //double-------------------------------
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_double();
      b[i][j]=rand_double();
      c[i][j]=0;
    }
  }//initialize double a[][],b[][],c[][]
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("double N=64, elapsed time: %f\n",elapsedTime );
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);
  //float-------------------------------
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_float();
      b[i][j]=rand_float();
      c[i][j]=0;
    }
  }//initialize float a[][],b[][],c[][]
   st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("float N=64, elapsed time: %f\n", elapsedTime);
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);

  ///////////////////////////////////////////////////////////////////
  
   //N=128
  n=128;
  //double-------------------------------
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_double();
      b[i][j]=rand_double();
      c[i][j]=0;
    }
  }//initialize double a[][],b[][],c[][]
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("double N=128, elapsed time: %f\n",elapsedTime );
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);
  //float-------------------------------
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_float();
      b[i][j]=rand_float();
      c[i][j]=0;
    }
  }//initialize float a[][],b[][],c[][]
   st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("float N=128, elapsed time: %f\n", elapsedTime);
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);

  /////////////////////////////////////////////////////////////////////

   //N=256
  n=256;
  //double-------------------------------
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_double();
      b[i][j]=rand_double();
      c[i][j]=0;
    }
  }//initialize double a[][],b[][],c[][]
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("double N=256, elapsed time: %f\n",elapsedTime );
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);
  //float-------------------------------
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_float();
      b[i][j]=rand_float();
      c[i][j]=0;
    }
  }//initialize float a[][],b[][],c[][]
   st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("float N=256, elapsed time: %f\n", elapsedTime);
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);

  ///////////////////////////////////////////////////////////////////

   //N=512
  n=512;
  //double-------------------------------
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_double();
      b[i][j]=rand_double();
      c[i][j]=0;
    }
  }//initialize double a[][],b[][],c[][]
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("double N=512, elapsed time: %f\n",elapsedTime );
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);
  //float-------------------------------
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_float();
      b[i][j]=rand_float();
      c[i][j]=0;
    }
  }//initialize float a[][],b[][],c[][]
   st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("float N=512, elapsed time: %f\n", elapsedTime);
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);


  //////////////////////////////////////////////////////////////////

   //N=1024
  n=1024;
  //double-------------------------------
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_double();
      b[i][j]=rand_double();
      c[i][j]=0;
    }
  }//initialize double a[][],b[][],c[][]
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("double N=1024, elapsed time: %f\n",elapsedTime );
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);
  //float-------------------------------
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_float();
      b[i][j]=rand_float();
      c[i][j]=0;
    }
  }//initialize float a[][],b[][],c[][]
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("float N=1024, elapsed time: %f\n", elapsedTime);
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);


  /////////////////////////////////////////////////////////////////////
  
   //N=2048
  n=2048;
  //double-------------------------------
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_double();
      b[i][j]=rand_double();
      c[i][j]=0;
    }
  }//initialize double a[][],b[][],c[][]
  st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("double N=2048, elapsed time: %f\n",elapsedTime );
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);
  //float-------------------------------
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=rand_float();
      b[i][j]=rand_float();
      c[i][j]=0;
    }
  }//initialize float a[][],b[][],c[][]
   st=e_time();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
  en=e_time();
  elapsedTime=en-st;
  printf("float N=2048, elapsed time: %f\n", elapsedTime);
  printf("-> %f MFLOPS\n", 2*(n*n*n)/(elapsedTime)/1.0e6);
  return 0;
}
