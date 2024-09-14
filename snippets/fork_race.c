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
    
    if (cpid > 0) { /* Parent process */
      for(i =0; i< 10;i++)
        printf("Parent: %d\n", i);
    } else if (cpid == 0) { /* Child process */
        for(i=0;i>-10;i--)
          printf("Child: %d\n", i);
    }
    return 0;
}
