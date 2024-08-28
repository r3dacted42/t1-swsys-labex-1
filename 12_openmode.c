/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       13 August 2024

12. Write a program to find out the opening mode of a file. Use fcntl.
========================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    char fname[128];
    printf("enter the filename to open: ");
    scanf("%s", fname);
    int fd = open(fname, O_RDWR | O_APPEND);
    if (fd < 0) {
        perror("perror response: ");
        return 0;
    }
    int mode = fcntl(fd, F_GETFL);
    printf("mode returned by fcntl: %o\n", mode);

    close(fd);
    
    return 0;
}

/*
Sample Execution:

$ runc 12_openmode.c
enter the filename to open: temp.txt
mode returned by fcntl: 102002

*/
