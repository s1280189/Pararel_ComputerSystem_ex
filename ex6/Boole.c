#include<omp.h>
#include<stdio.h>

static long num_steps=10000000000;
double step;
#define N 1 //1~8,THREADS

void main()
{
  int  i,id,nthrds, nthreads;
  double pi, sum[N];

  double st, en;

  st=omp_get_wtime();

  step=1.0/(double) num_steps;

  omp_set_num_threads(N);

  double x1,x0,dx;
    double integral;

    id=omp_get_thread_num();
    nthrds=omp_get_num_threads();

    if(id==0) nthreads = nthrds;

    sum[id]=0.0;
    #pragma omp parallel for
    for(i=id; i<num_steps; i=i+nthrds){
      x0=4/(1+ i*i);
      x1=4/(1+ (i+nthrds)*(i+nthrds));
      dx=((i+nthrds) - i)/4;
      
      sum[id] += ((id+nthrds)-id)/90 * (7*x0 + 32* 4/(1 + (i+dx)*(i+dx)) +
					12* 4/(1+ (i+2*dx)*(i+2*dx)) + 32* 4/(i+(3*dx)*(3*dx)) +
					7*x1);
    }

    for(i=0, integral=0.0;i<nthreads;i++) integral += sum[i]*step;

    en=omp_get_wtime();

    printf("Elapsed time %e sec\n", en-st);
}
