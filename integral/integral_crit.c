#include <stdio.h>
#include <omp.h>

#define NTHREADS 4

static long num_steps = 100000000; // one hundred million 
double step; 

int main() 
{ 
  int i, j, nthreads;
  double pi, full_sum;
  double start_time, run_time;

  omp_set_num_threads(NTHREADS);
  
  step = 1.0 / (double) num_steps; // need to cast to double because we initialized it as long
  pi = 0.0;
  full_sum = 0.0;
  start_time = omp_get_wtime();

  // start of parallel region
  #pragma omp parallel
  {
    int i;
    int id = omp_get_thread_num();
    int numthreads = omp_get_num_threads();
    double x, partial_sum;

    if (id == 0) nthreads = numthreads; // Only the master threads can do this assignment
    
    for (i = id; i < num_steps; i+= numthreads){
      x = ( i + 0.5 ) * step;
      partial_sum += 4.0 / (1.0 + x * x);
    }

    #pragma omp critical
      full_sum += partial_sum;
  } // END OF PARALLEL region

  pi = step * full_sum;
  run_time = omp_get_wtime() - start_time;

 printf("pi = \%f, \%d steps, \%f secs\n",
         pi, num_steps, run_time);
}
