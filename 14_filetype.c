/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       13 August 2024

14. Write a program to find the type of a file.
    a. Input should be taken from command line.
    b. program should be able to identify any type of a file.
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// prototype
int lstat(const char *pathname, struct stat *statbuf);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return -1;
    }

    char *fname = argv[1];
    struct stat info;
    int result = lstat(fname, &info);
    if (result < 0) {
        perror("perror response: ");
        return result;
    }
    printf("the given pathname is a ");
    switch (info.st_mode & __S_IFMT) {
        case __S_IFSOCK: printf("socket file\n"); break;
        case __S_IFLNK: printf("symbolic link\n"); break;
        case __S_IFREG: printf("regular file\n"); break;
        case __S_IFBLK: printf("block device\n"); break;
        case __S_IFDIR: printf("directory\n"); break;
        case __S_IFCHR: printf("character device\n"); break;
        case __S_IFIFO: printf("named pipe (FIFO)\n"); break;
        default: printf("<unknown type>\n");
    }

    return 0;
}

/*
Sample Execution:

$ runc 14_filetype.c tempsl.txt
the given pathname is a symbolic link

$ runc 14_filetype.c /dev/sda
the given pathname is a block device

$ runc 14_filetype.c myfifo
the given pathname is a named pipe (FIFO)

*/
