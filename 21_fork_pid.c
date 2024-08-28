/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

21. Write a program, call fork and print the parent and child process id.
========================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    if (!fork()) {
        // run in child process
        printf("pid of child: %d, pid of parent: %d\n", getpid(), getppid());
    } else {
        wait(0);
    }
    return 0;
}

/*
Sample Execution:

$ runc 21_fork_pid.c
pid of child: 260392, pid of parent: 260391

*/
