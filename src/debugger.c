//
// Created by karan on 3/11/16.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>

void run_debugger(pid_t child_pid)
{
    printf("The Debugger has started.\n");

    int wait_status;
    wait(&wait_status);

    long int instruction_counter = 0;

    while(WIFSTOPPED(wait_status))
    {
        instruction_counter++;
        ptrace(PTRACE_SINGLESTEP, child_pid, 0, 0);
        wait (&wait_status);
    }
    printf ("Total Lines analyzed : %ld", instruction_counter);
}