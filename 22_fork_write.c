/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

22. Write a program, open a file, call fork, and then write to the file by both 
the child as well as the parent processes. Check output of the file.
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    char *fname;
    if (argc != 2) {
        fname = calloc(128, sizeof(char));
        printf("enter the filename to write to: ");
        scanf("%s", fname);
    } else {
        fname = argv[1];
    }
    int fd = open(fname, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (!fork()) {
        // inside child process
        char msg[] = "written from child process\n";
        write(fd, msg, sizeof(msg) - 1);
    } else {
        char msg[] = "written from parent process\n";
        write(fd, msg, sizeof(msg) - 1);
        close(fd);
        wait(NULL);
        fd = open(fname, O_RDONLY);
        char buf[1024];
        int rd = read(fd, buf, sizeof(buf));
        buf[rd] = '\0';
        printf("read %d bytes from file:\n%s", rd, buf);
    }
    close(fd);

    return 0;
}

/*
Sample Execution:

$ runc 22_fork_write.c
enter the filename to write to: temp_fork.txt
read 55 bytes from file:
written from parent process
written from child process

$ cat temp_fork.txt
written from parent process
written from child process

*/
