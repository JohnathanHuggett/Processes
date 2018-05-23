// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // printf("hello world (pid: %d)\n", (int)getpid());

    int rc = fork();

    // negative number indicates failure
    if (rc < 0)
    {
        printf("fork failed\n");
        exit(1);
    }
    // zero indicates child has been fork();
    else if (rc == 0)
    {
        printf("hello\n");
    }
    // greater than 0 = parent
    else
    {
        // waitpid() needs to go here
        int wc = waitpid(rc, NULL, 0);
        printf("goodbye\n");
    }

    return 0;
}
