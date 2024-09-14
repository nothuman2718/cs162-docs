#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void signal_callback_handler(int signum){
  printf("In the defined signal handler callback");
  exit(1);
}

int main(){
  struct sigaction sa;
  sa.sa_flags=0;
  sigemptyset(&sa.sa_mask);
  sa.sa_handler = signal_callback_handler;
  sigaction(SIGINT, &sa, NULL);
  while(1){}
}
