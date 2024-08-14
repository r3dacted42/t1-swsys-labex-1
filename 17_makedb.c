/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       13 August 2024

17. Write a program to simulate online ticket reservation. Implement write lock.
---> Write a program to open a file, store a ticket number and exit. 
Write a separate program, to open the file, implement write lock, read the 
ticket  number, increment the number and print the new ticket number then close 
the file.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    printf("creating db file...\n");
    char fname[] = ".db";
    int fd = open(fname, O_CREAT | O_EXCL | O_WRONLY, 0777);
    if (fd < 0) {
        perror("failure while creating file: ");
        return -1;
    }
    struct db {
        int ticket_num;
    } item;
    item.ticket_num = 0;
    int written = write(fd, &item, sizeof(item));
    if (written == sizeof(item)) {
        printf("db file successfully created!\n");
    } else {
        perror("failure while writing to file: ");
        printf("wrote %d bytes\n", written);
    }
    close(fd);

    return 0;
}