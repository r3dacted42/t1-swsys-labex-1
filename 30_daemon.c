/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       23 August 2024

30. Write a program to run a script at a specific time using a Daemon process.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int init_daemon() {
    int pid = fork();
    if (pid > 0) return 0;
    if (pid < 0) return -1;
    pid = getpid();

    setsid();
    umask(0);
    int fd = open(".log", O_RDWR | O_CREAT | O_APPEND, 0777);
    char msg[128] = {0};
    sprintf(msg, "[%d] daemon started at %ld\n", pid, time(NULL));
    write(fd, msg, sizeof(msg));
    long int init_time = time(NULL);
    while (1) {
        sprintf(msg, "[%d] daemon still running at %ld\n", pid, time(NULL));
        write(fd, msg, sizeof(msg));
        system("sh 30_runner.sh");
        sleep(10);
        if (init_time > 0 && time(NULL) - init_time > 30) {
            system("sh 30_runner.sh hehe");
            init_time = -1;
        }
    }
    return 0;    
}

int main(void) {
    return init_daemon();
}