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
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#include "log.hxx"

void logger (enum category eCategory, enum destination eDestination, const char* pSourceFile, const char* pMessage)
{
    char* pFullMessage = (char *) malloc(200);

    switch (eCategory)
    {
        case EMERGENCY : strcpy(pFullMessage, "EMERGENCY >>"); break;
        case WARNING : strcpy(pFullMessage, "WARNING   >>"); break;
        case DEBUG : strcpy(pFullMessage, "DEBUG     >>"); break;
        case INFO : strcpy(pFullMessage, "INFO      >>"); break;
        default: strcpy(pFullMessage, "INFO      >>");
    }

    strcat(pFullMessage, pSourceFile);
    strcat(pFullMessage, " : ");
    strcat(pFullMessage, pMessage);

    errno = 0;
    FILE* file;
    file = fopen("./../log/Memory_Smith.log", "a");

    if (!file)
        printf ("Unable to open logging file for appending. errorno = %d\n", errno);
    else
    {
        eDestination == 0 ? fprintf(file, pFullMessage) : printf("%s", pFullMessage);
        fclose(file);
    }
    return;
}
