// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // printf("hello world (pid: %d)\n", (int)getpid());
    FILE *file;

    file = fopen("file.txt", "w+"); // w+ allows to read and write from the file
    fprintf(file, "%s %s %s %d", "We", "are", "in", 2018);

    int rc = fork();

    if (rc < 0)
    {
        printf("fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("hello, child here (pid: %d) \n", (int)getpid());
        printf("file discriptor: %d\n", file);
    }
    else
    {
        printf("hello, parent here (pid: %d) of child %d\n", (int)getpid(), rc);
        printf("file discriptor: %d\n", file);
    }
    return 0;
}
