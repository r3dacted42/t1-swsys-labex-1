/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       10 August 2024

8. Write a program to open a file in read only mode, read line by line 
and display each line as it is read. Close the file when end of file 
is reached.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 128

int main(void) {
    char fname[128];
    printf("enter filename to read: ");
    scanf("%s", fname);
    int fd = open(fname, O_RDONLY);
    if (fd == -1) {
        perror("perror response: ");
        return 1;
    }
    char buf[BUF_SIZE];
    for (int i = 0, bytesread = 1, foundEOL = 1; bytesread > 0; ) {
        bytesread = read(fd, buf, BUF_SIZE);
        if (bytesread) {
            int written = 0;
            do {
                int lineend = written - 1, lineidx = 0;
                char linebuf[BUF_SIZE];
                while (buf[++lineend] != '\n' && lineend < bytesread && lineidx < BUF_SIZE - 1) 
                    linebuf[lineidx++] = buf[lineend];
                linebuf[lineidx] = '\0';
                if (foundEOL) printf("\n%d: %s", i++, linebuf);
                else printf("%s", linebuf);
                foundEOL = (buf[lineend] == '\n');
                written += lineidx + 1;
            } while(written < bytesread);
        }
        for (int i = 0; i < BUF_SIZE; i++) buf[i] = 0;
    }
    printf("\n");
    close(fd);
    
    return 0;
}