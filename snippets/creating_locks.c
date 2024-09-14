#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> // P - POSIX

/*
 The **pthread** library (POSIX threads) is a C/C++ library for creating and managing threads in Unix-like systems. 
 It allows for concurrent execution within a single process, 
 where multiple threads share memory but have separate execution contexts (stacks, registers).

### Key Concepts:
- **Threads**: Smallest unit of execution within a process.
- **pthread_create()**: Used to create threads.
- **pthread_join()**: Waits for a thread to finish.
- **pthread_mutex_t**: Mutex for synchronizing access to shared resources.
- **pthread_cond_t**: Condition variables for coordinating thread execution.

### Internals:
- Threads share memory but require synchronization (e.g., mutexes) to avoid race conditions.
- Context switching between threads is managed by the OS.
- The library provides tools for controlling thread scheduling, attributes, and termination.

The **pthread** library helps improve performance by enabling parallelism, 
      especially useful in CPU-intensive or I/O-bound applications.
*/

int global=162;
// mutex -> mutual exclusion
// The below statement refers Naming the lock 
pthread_mutex_t common_lock = PTHREAD_MUTEX_INITIALIZER;

void *threadFun(void *threadid){
  long tid=(long)threadid;
  pthread_mutex_lock(&common_lock);
  int global2=global++;
  pthread_mutex_unlock(&common_lock);
  printf("Thread #%lx stack:  %lx global: %lx (%d)\n", tid, (unsigned long) &tid, (unsigned long) &global, global2);
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  long t;
  int nthreads=2;
  if(argc > 1){
    nthreads=atoi(argv[1]);
  }
  pthread_t * threads = malloc(nthreads* sizeof(pthread_t));

  // %lx refers print the variable of long in hexadecimal
  printf("Main Stack: %lx, global 1: %lx, global 2:%lx, (%d)\n", (unsigned long) &t, (unsigned long) &global,(unsigned long) &global2, global);

  for(t=0;t<nthreads;t++){
    // The 4th argument is the argument which we gonna send for threadFun function
    int ret= pthread_create(&threads[t],NULL,threadFun, (void *)t);
    // threadFun is a pointer to function which has argument of type void* and returns void*
    if(ret){
      printf("Error returned from create_thread()");
      exit(-1);
    }
  } 
 for(t=0;t<nthreads;t++){
    pthread_join(threads[t], NULL);
  }
  pthread_exit(NULL);
}
