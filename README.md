# Memory-Smith
Tool to tinker with Memory, peak and poke around a process's memory.

## Dependencies
1. Cmake

## Building the Project
1. `Clone` the Repository
2. `cd Memory-Smith`
3. `mkdir build`
4. `cd build`
5. `cmake ..`

## Running the project
1. Make a Hello World program in file `foo.c`
```
#include <stdio.h>
void main()
{
    printf("Hey, There");
}
```
2. Compile this on gcc (or any other) compiler by `gcc -o foo foo.c`

3. Run this project by `main foo`
