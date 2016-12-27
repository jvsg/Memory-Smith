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
#include <sys/ptrace.h>
#include <unistd.h>

#include "log.hxx"

void run_target (const char* executable_name)
{
    logger(INFO, LOG_FILE, __FILE__, "Attempting to run the executable.\n");

    if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0)
    {
        logger(EMERGENCY, LOG_FILE, __FILE__, "Oops, Problem with Ptracing the Program you requested\n");
        return;
    }
    else
    {
        if (execl(executable_name, executable_name, 0, NULL))
            logger (EMERGENCY, LOG_FILE, __FILE__, "Oops, Something went wrong with Executing the program.\n");
    }
}

