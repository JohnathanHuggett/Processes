// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main()
{
    // hold incoming data being written
    char inbuf[MSGSIZE];

    // arr will hold read and write file
    int p[2];

    // invoke the pipe and pass in the reading and writting arr
    pipe(p);

    // call fork to make child
    int rc = fork();

    if (rc < 0)
    {
        printf("fork failed\n");
        exit(1);
    }

    else if (rc == 0)
    {
        printf("Child -> program is writting...\n");

        // child writes to the writting element in arr
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        write(p[1], "custom msg", MSGSIZE);
    }

    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("Parent -> program is printing...\n");

        for (int i = 0; i < 4; i++)
        {
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
    }
    return 0;
}
