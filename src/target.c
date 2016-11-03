//
// Created by karan on 2/11/16.
//
#include <stdio.h>
#include <sys/ptrace.h>
#include <unistd.h>

void run_target (const char* executable_name)
{
    printf("Attempting to run the executable.\n");

    if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0)
    {
        printf("Oops, Problem with Ptracing the Program you requested\n");
        return;
    }
    else
    {
        if (execl(executable_name, executable_name, 0, NULL))
            printf ("Oops, Something went wrong with Executing the program.\n");
    }
}

