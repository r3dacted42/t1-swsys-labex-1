/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       13 August 2024

11. Write a program to open a file, duplicate the file descriptor and 
append the file with both the descriptors and check whether the file is 
updated properly or not.
    a. use dup
    b. use dup2
    c. use fcntl
========================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void check_file_contents(int fd, char name[]) {
    int prevpos = lseek(fd, 0, SEEK_CUR);
    lseek(fd, 0, SEEK_SET);
    char *buf = (char*)calloc(128, sizeof(char));
    printf("contents of file after appending with fd created by %s:\n", name);
    while (read(fd, buf, 1)) {
        printf("%s", buf);
    }
    free(buf);
    printf("\n");
    lseek(fd, prevpos, SEEK_SET);
}

void use_dup(int oldfd) {
    int newfd = dup(oldfd);
    lseek(newfd, 0, SEEK_END);
    char msg[] = "this was written through dup.\n";
    write(newfd, msg, sizeof(msg) / sizeof(char));
    check_file_contents(newfd, "dup");
    close(newfd);
}

void use_dup2(int oldfd) {
    int newfd = 10 + rand() % 64;
    dup2(oldfd, newfd);
    lseek(newfd, 0, SEEK_END);
    char msg[] = "this was written through dup2.\n";
    write(newfd, msg, sizeof(msg) / sizeof(char));
    check_file_contents(newfd, "dup2");
    close(newfd);
}

void use_fcntl(int oldfd) {
    int newfd = fcntl(oldfd, F_DUPFD);
    lseek(newfd, 0, SEEK_END);
    char msg[] = "this was written through fcntl.\n";
    write(newfd, msg, sizeof(msg) / sizeof(char));
    check_file_contents(newfd, "fcntl");
    close(newfd);
}

int main(void) {
    char fname[128];
    printf("enter the filename to open: ");
    scanf("%s", fname);
    int fd = open(fname, O_CREAT | O_RDWR, 0666);
    if (fd < 0) {
        perror("perror response: ");
        return 0;
    }
    lseek(fd, 0, SEEK_END);
    char msg[] = "this was written through open.\n";
    write(fd, msg, sizeof(msg) / sizeof(char));
    check_file_contents(fd, "open");

    use_dup(fd);
    use_dup2(fd);
    use_fcntl(fd);

    close(fd);
    return 0;
}

/*
Sample Execution:

$ runc 11_dupfd.c
enter the filename to open: tempdup.txt
contents of file after appending with fd created by open:
this was written through open.

contents of file after appending with fd created by dup:
this was written through open.
this was written through dup.

contents of file after appending with fd created by dup2:
this was written through open.
this was written through dup.
this was written through dup2.

contents of file after appending with fd created by fcntl:
this was written through open.
this was written through dup.
this was written through dup2.
this was written through fcntl.

$ cat tempdup.txt
this was written through open.
this was written through dup.
this was written through dup2.
this was written through fcntl.

*/
