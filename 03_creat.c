/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       8 August 2024

3. Write a program to create a file and print the file descriptor value. 
Use creat ( ) system call
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// syscall function prototype
int creat(const char *pathname, mode_t mode);

int main(void) {
    char fname[128];
    printf("enter the filename to create: ");
    scanf("%s", fname);
    int fd = creat(fname, 0777);
    if (fd != -1) printf("fd of created file: %d\n", fd);
    else perror("perror response: ");
    if (fd != -1) close(fd);

    return 0;
}