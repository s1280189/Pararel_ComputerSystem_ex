#include<omp.h>
#include<stdio.h>

static long num_steps=100000;
double step;
#define N 2 //1~8,THREADS

void main()
{
  int  i,id,nthrds, nthreads;
  double pi, sum[N];

  double st, en;

  st=omp_get_wtime();

  step=1.0/(double) num_steps;

  omp_set_num_threads(N);

    double x1,x0;
    double integral;

    id=omp_get_thread_num();
    nthrds=omp_get_num_threads();

    if(id==0) nthreads = nthrds;

    sum[id]=0.0;
    #pragma omp parallel for
    for(i=id; i<num_steps; i=i+nthrds){
      x0=i*i;
      x1=(i+nthrds)*(i+nthrds);
      sum[id] += ((id+nthrds)-id)/6 * (x0 + 4*( ((x0+x1)/2) * ((x0+x1)/2) ) + x1);
    }

    for(i=0, integral=0.0;i<nthreads;i++) integral += sum[i]*step;

    en=omp_get_wtime();

    printf("Simpson's integral is %20.15e\n", integral);
    printf("Elapsed time %e sec\n", en-st);
}
