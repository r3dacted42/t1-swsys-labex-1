/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       10 August 2024

7. Write a program to copy file1 into file2 ($cp file1 file2).
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    char *srcname, *dstname;
    if (argc == 3) {
        srcname = argv[1];
        dstname = argv[2];
    } else {
        srcname = calloc(128, sizeof(char));
        printf("enter the source file pathname: ");
        scanf("%s", srcname);
        dstname = calloc(128, sizeof(char));
        printf("enter the destination file pathname: ");
        scanf("%s", dstname);
    }    
    
    int srcfd = open(srcname, O_RDONLY);
    if (srcfd == -1) {
        perror("perror src file: ");
        return 1;
    }
    int dstfd = open(dstname, O_WRONLY | O_CREAT | O_EXCL, 0666);
    if (dstfd == -1) {
        perror("perror dst file: ");
        close(srcfd);
        return 2;
    }
    
    char buf[128];
    long bytesread;
    while (bytesread = read(srcfd, buf, 128)) {
        printf("read %ld bytes, ", bytesread);
        printf("wrote %ld bytes\n", write(dstfd, buf, bytesread));
    }
    printf("file successfully copied!\n");
    close(srcfd);
    close(dstfd);
    if (argc != 3) {
        free(srcname);
        free(dstname);
    }
    
    return 0;
}