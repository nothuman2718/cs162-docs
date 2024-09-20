#define BUF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/*A pipe in Linux provides a unidirectional communication channel between processes. 
 * It creates two file descriptors: one for writing (`pipe_fd[1]`) and one for reading (`pipe_fd[0]`).
 * Data written to the write end is buffered by the kernel and can be read from the read end. When `write()` is called, 
 * the message is placed into the pipe's buffer, and `read()` retrieves it from the buffer. 
 * The pipe is closed after use to release system resources. In essence, the pipe allows data to flow from the writer 
 * to the reader within the same or different processes.*/


int main(int argc, char *argv[])
{
  char * msg = "Message in a pipe\n";
  char buf[BUF_SIZE];
  int pipe_fd[2];

  if(pipe(pipe_fd)==-1){
    fprintf(stderr, "Pipe Failed. \n");
    return EXIT_FAILURE;
  }

  ssize_t writelen = write(pipe_fd[1], msg, strlen(msg)+1);
  printf(" Sent: %s [%ld, %ld]\n", msg, strlen(msg)+1, writelen);

  ssize_t readlen = read(pipe_fd[0], buf, BUF_SIZE);
  printf(" Recieved: %s [%ld]\n", msg, readlen);


  close(pipe_fd[0]);
  close(pipe_fd[1]);
  return EXIT_SUCCESS;
}
