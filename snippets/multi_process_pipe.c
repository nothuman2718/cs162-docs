#define BUF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char * msg = "Message in a pipe\n";
  char buf[BUF_SIZE];
  int pipe_fd[2];

  if(pipe(pipe_fd)==-1){
    fprintf(stderr, "Pipe Failed. \n");
    return EXIT_FAILURE;
  }

  pid_t pid = fork();

  if(pid<0){
    fprintf(stderr, " Fork Failed.\n");
    return EXIT_FAILURE;
  }

  if(pid!=0){
    ssize_t writelen = write(pipe_fd[1], msg, strlen(msg)+1);
    printf(" Sent: %s [%ld, %ld]\n", msg, strlen(msg)+1, writelen);
    close(pipe_fd[0]);
  }else{
    ssize_t readlen = read(pipe_fd[0], buf, BUF_SIZE);
    printf(" Recieved: %s [%ld]\n", msg, readlen);
    close(pipe_fd[1]);
  }

  return EXIT_SUCCESS;
}

