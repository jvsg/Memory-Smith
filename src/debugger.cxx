/*
* Copyright 2016 Jaskaran Singh <jvsg1303@gmail.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*        http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>

#include "log.hxx"

void run_debugger(pid_t child_pid)
{
    logger(INFO, LOG_FILE, __FILE__, "The Debugger has started.\n");

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