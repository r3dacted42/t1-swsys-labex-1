/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       10 August 2024

5. Write a program to create five new files with infinite loop. 
Execute the program in the background and check the file descriptor 
table at /proc/pid/fd.
========================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    int cpfd = open("2_infloop.c", O_RDONLY);
    char writebuf[1024];
    read(cpfd, writebuf, 1023);
    close(cpfd);
    for (int i = 0; i < 5; i++) {
        char fname[32];
        sprintf(fname, "inf_%d.c", i);
        int fd = creat(fname, O_CREAT);
        write(fd, writebuf, 1023);
    }
    // wait for SIGTERM
    while (1);
    
    return 0;
}

/*
Check 05_checkfd.sh for Sample Execution...
*/