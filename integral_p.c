#include <stdio.h>
#include <omp.h>

#define NTHREADS 4

static long num_steps = 100000000; // one hundred million 
double step; 

int main() 
{ 
  int i, j, actual_nthreads;
  double pi, start_time, run_time;
  double sum[NTHREADS] = {0.0};

  step = 1.0 / (double) num_steps; // need to cast to double because we initialized it as long
  
  omp_set_num_threads(NTHREADS);

  start_time = omp_get_wtime();

  // start of parallel region
  #pragma omp parallel
  {
    int i;
    int id = omp_get_thread_num();
    int numthreads = omp_get_num_threads();
    double x;

    if (id == 0) actual_nthreads = numthreads; // Only the master threads can do this assignment
    
    for (i = id; i < num_steps; i+= numthreads){
      x = ( i + 0.5 ) * step;
      sum[id] += 4.0 / (1.0 + x * x);
    }
  } // END OF PARALLEL region
  pi = 0.0;

  for (i = 0; i < actual_nthreads; i++)
    pi += sum[i];

  pi = step * pi;
  run_time = omp_get_wtime() - start_time;

 printf("pi = \%f, \%d steps, \%f secs\n",
         pi, num_steps, run_time);
}
