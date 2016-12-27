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
#include <sys/unistd.h>

#include "target.hxx"
#include "debugger.hxx"
#include "log.hxx"

int main(int argc, char** argv)
{
    printf ( "************  Welcome to Memory Tinkerer Core  ************\n" );

    if (argc > 2)
    {
        logger (EMERGENCY, LOG_FILE, __FILE__, "You supplied too many arguments. Take it easy.\n");
        return 1;
    }
    else if (argc < 2)
    {
        logger (EMERGENCY, LOG_FILE, __FILE__, "Executable Name Expected as an argument. Did you forgot to supply it?\n");
        return 1;
    }

    pid_t child_pid = fork();

    if (child_pid == 0)
        run_target(argv[1]);
    else if (child_pid > 0)
        run_debugger(child_pid);
    else
    {
        logger (EMERGENCY, LOG_FILE, __FILE__, "Problem while forking.");
        return 0;
    }

}