#include <stdio.h>
#include <sys/types.h>
#include <sys/unistd.h>

#include "target.h"
#include "debugger.h"

int main(int argc, char** argv)
{
    printf ( "************  Welcome to Memory Tinkerer Core  ************\n" );

    if (argc > 2)
    {
        printf ("ERROR : You supplied too many arguments. Take it easy.\n");
        return 1;
    }
    else if (argc < 2)
    {
        printf ("ERROR : Executable Name Expected as an argument. Did you forgot to supply it?\n");
        return 1;
    }

    pid_t child_pid = fork();

    if (child_pid == 0)
        run_target(argv[1]);
    else if (child_pid > 0)
        run_debugger(child_pid);
    else
    {
        printf ("ERROR : Problem while forking.");
        return 0;
    }

}