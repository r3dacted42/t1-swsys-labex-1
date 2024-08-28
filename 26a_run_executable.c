/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

26. Write a program to execute an executable program.
    a. use some executable program <---
    b. pass some input to an executable program. (for example execute an 
       executable of $./a.out name)
========================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r = system("./26_executable.o");
    if (r != 0) {
        printf("error while executing program\n");
    }
    return 0;
}

/*
Sample Execution:

$ runc 26a_run_executable.c
no cmd line args received

*/
