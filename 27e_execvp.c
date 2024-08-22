/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

27. Write a program to execute ls -Rl by the following system calls
    a. execl
    b. execlp
    c. execle
    d. execv
    e. execvp <---
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    if (!fork()) {
        char *args[] = {"ls", "-Rl", NULL, ""};
        return execvp("ls", args);
    }

    wait(0);
    return 0;
}