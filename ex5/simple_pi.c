#include <omp.h>
#include <stdio.h>

static long num_steps = 1000000000;
double step;
#define PAD 8
#define NUM_THREADS 6

void main ()
{
  int i, nthreads;
  double pi, sum[NUM_THREADS][PAD];

  double st, en;

  st = omp_get_wtime();
  
  step = 1.0/(double) num_steps;

  omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
  {
    int i, id,nthrds;
    double x;
    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();
    if (id == 0) nthreads = nthrds;
    
    for (i=id, sum[id][0]=0.0;i< num_steps; i=i+nthrds) {
      x = (i+0.5)*step;
      sum[id][0] += 4.0/(1.0+x*x);
    }
  }

  for(i=0, pi=0.0;i<nthreads;i++) pi += sum[i][0] * step;
  en = omp_get_wtime();

  printf("Aprroximate PI is %20.15e\n", pi);
  printf("Elapased time %e sec\n", en-st);
}
