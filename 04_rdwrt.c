/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       8 August 2024

4. Write a program to open an existing file with read write mode. 
Try O_EXCL flag also.
========================================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    char fname[128];
    printf("enter the filename to open: ");
    scanf("%s", fname);
    int fd = open(fname, O_RDWR);
    // if O_CREAT | O_EXCL is used, then create fails with EEXIST
    // in case the file already exists. also, symbolic links are 
    // not followed in the pathname.
    if (fd != -1) printf("fd of opened file: %d\n", fd);
    else perror("perror response: ");
    if (fd != -1) close(fd);

    return 0;
}

/*
Sample Execution:

$ runc 04_rdwrt.c
enter the filename to open: tempfile.txt
fd of opened file: 3

--using O_CREAT | O_EXCL
$ runc 04_rdwrt.c
enter the filename to open: tempfile.txt
perror response: : File exists

*/
