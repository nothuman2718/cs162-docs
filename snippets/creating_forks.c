#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For process management, file handling, IO operations
#include <sys/types.h> // Provides the types for low-level operations and system calls

int main(int argc, char *argv[])
{
    pid_t cpid, mypid;
    pid_t pid = getpid(); /* get current process PID */
    printf("Parent pid: %d\n", pid);

    cpid = fork();
    
    if (cpid > 0) { /* Parent process */
        mypid = getpid(); // Parent's PID
        printf("[%d] parent of [%d]\n", mypid, cpid);
    } else if (cpid == 0) { /* Child process */
        mypid = getpid(); // Child's PID
        printf("[%d] child\n", mypid);
    } else { /* fork() failed */
        perror("Fork Failed");
    }
    return 0;
}
