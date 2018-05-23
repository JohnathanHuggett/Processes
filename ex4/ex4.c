// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // printf("hello world (pid: %d)\n", (int)getpid());
    int rc = fork();

    // execv() args and size
    char *args[2];
    args[0] = "/bin/ls";
    args[1] = NULL;

    // printf("args:%s\n", args[0]);

    if (rc < 0)
    {
        printf("fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child: (pid: %d)\n", (int)getpid());
        execv(args[0], args);
        printf("this should not print\n");
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("Parnet: (pid: %d)\n", (int)getpid());
    }
    return 0;
}
