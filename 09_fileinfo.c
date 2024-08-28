/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       13 August 2024

9. Write a program to print the following information about a given file.
    a. inode
    b. number of hard links
    c. uid
    d. gid
    e. size
    f. block size
    g. number of blocks
    h. time of last access
    i. time of last modification
    j. time of last change
========================================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// prototype
int stat(const char *pathname, struct stat *statbuf);

int main(void) {
    struct stat buf;
    char fname[128];
    printf("enter the filename to get info for: ");
    scanf("%s", fname);
    stat(fname, &buf);
    printf("\nfile info:\n");
    printf("a. inode: %lu\nb. num. of hard links: %lu\n", buf.st_ino, buf.st_nlink);
    printf("c. uid: %d\nd. gid: %d\n", buf.st_uid, buf.st_gid);
    printf("e. size: %ld\nf. block size: %ld\n", buf.st_size, buf.st_blksize);
    printf("g. num. of blocks: %ld\nh. time of last access: %ld\n", buf.st_blocks, buf.st_atime);
    printf("i. time of last mod.: %ld\nj. time of last change: %ld\n", buf.st_mtime, buf.st_ctime);
    return 0;
}

/*
Sample Execution:

$ runc 09_fileinfo.c
enter the filename to get info for: temphl.txt

file info:
a. inode: 29597
b. num. of hard links: 2
c. uid: 1000
d. gid: 1000
e. size: 30
f. block size: 4096
g. num. of blocks: 8
h. time of last access: 1724836929
i. time of last mod.: 1724322335
j. time of last change: 1724837361

*/
