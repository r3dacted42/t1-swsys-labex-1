/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

24. Write a program to create an orphan process.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    int pid = fork();
    if (!pid) {
        // orphan kid
        pid = getpid();
        printf("i'm %d, my parent (%d) will leave me soon :(\n", pid, getppid());
        sleep(2);
        printf("\ni have been adopted by %d :D\nthis is my status (head):\n", getppid());
        char cmd[128];
        sprintf(cmd, "cat /proc/%d/status | head -n 7", pid);
        return system(cmd);
    }
    sleep(1);
    return 0;
}