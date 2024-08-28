#!/bin/bash

# Name:       Priyansh Agrahari
# Reg. No.:   MT2024120
# Date:       22 August 2024

# 26. Write a program to execute an executable program.
#     a. use some executable program
#     b. pass some input to an executable program. (for example execute an 
#        executable of $./a.out name)

echo "creating executable program to run using 26(a) and 26(b)...";
echo '''#include <stdio.h>

int main(int argc, char **argv) {
    if (argc > 1) {
        printf("received %d cmd line args:\\n", argc - 1);
        for (int i = 1; i < argc; i++) {
            printf("%d : %s\\n", i, argv[i]);
        }
        char buf[128];
        scanf("%[^\\n]", buf);
        printf("read from stdin: %s\\n", buf);
    } else {
        printf("no cmd line args received\\n");
    }
    return 0;
}''' | gcc -o 26_executable.o -xc -;

<<sample
Sample Execution:

$ sh 26_create_executable.sh
creating executable program to run using 26(a) and 26(b)...

$ ll
...
-rw-r--r-- 1 r3dacted42 r3dacted42   831 Aug 22 14:35 26_create_executable.sh
-rwxr-xr-x 1 r3dacted42 r3dacted42 16104 Aug 28 17:03 26_executable.o*
-rw-r--r-- 1 r3dacted42 r3dacted42   479 Aug 22 14:32 26a_run_executable.c
...

sample
