/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

25. Write a program to create three child processes. The parent should wait 
for a particular child (use waitpid system call).
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    char cmd[128];
    int pid_1 = fork();
    if (!pid_1) {
        // child 1
        printf("i'm the first child, pid %d\n", getpid());
        return 0;
    }
    int pid_2 = fork();
    if (!pid_2) {
        // child 2
        printf("i'm the second child, pid %d\n", getpid());
        return 0;
    }
    int pid_3 = fork();
    if (!pid_3) {
        // child 3
        printf("i'm the favourite child, pid %d\n", getpid());
        return 0;
    }
    waitpid(pid_3, NULL, 0);

    printf("\nfirst child status:\n");
    sprintf(cmd, "cat /proc/%d/status | head -n 6", pid_1);
    system(cmd);
    printf("\nsecond child status:\n");
    sprintf(cmd, "cat /proc/%d/status | head -n 6", pid_2);
    system(cmd);
    printf("\nfavourite child status:\n");
    sprintf(cmd, "cat /proc/%d/status | head -n 6", pid_3);
    system(cmd);
    
    return 0;
}