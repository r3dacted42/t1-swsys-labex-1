/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

23. Write a program to create a Zombie state of the running program.
========================================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    int pid = fork();
    if (!pid) {
        // zombie kid
        printf("look for %d, i will be a zombie :D\n", getpid());
        return 0;
    }
    sleep(1);
    printf("press enter to view status of child process:");
    getchar(); // keep waiting for input
    char cmd[128];
    sprintf(cmd, "cat /proc/%d/status | head -n 6", pid);
    return system(cmd);
}

/*
Sample Execution:

$ runc 23_zombie.c
look for 260779, i will be a zombie :D
press enter to view status of child process:
Name:   run-1724844560.
State:  Z (zombie)
Tgid:   260779
Ngid:   0
Pid:    260779
PPid:   260778

*/
