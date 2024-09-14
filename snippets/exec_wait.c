#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For process management, file handling, IO operations
#include <sys/types.h> // Provides the types for low-level operations and system calls

int main(int argc, char *argv[])
{
    pid_t cpid, mypid;
    pid_t pid = getpid(); /* get current process PID */
    printf("Parent pid: %d\n", pid);

    int i;
    cpid = fork();
    int status;

    if (cpid > 0) { /* Parent process */
      wait(&status); // Parent waits till the execution of its child and stores the exit value in the status variable
    //
  } else if (cpid == 0) { /* Child process */
      char* args[] = {"ls", "-l", NULL};
      execv("/bin/ls",args);
      perror("execv");
      exit(1);
  }
    return 0;
}
