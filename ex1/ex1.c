// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // printf("hello world (pid: %d)\n", (int)getpid());
    int x = 100;

    int rc = fork();

    if (rc < 0)
    {
        printf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int)getpid());
        x = 20;
        printf("int x: %d\n", x);
    }
    else
    {
        printf("hello, parent here (pid: %d) of child %d\n", (int)getpid(), rc);
        x = 10;
        printf("int x: %d\n", x);
    }

    return 0;
}
