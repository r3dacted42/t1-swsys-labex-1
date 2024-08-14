/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       13 August 2024

17. Write a program to simulate online ticket reservation. Implement write lock.
Write a program to open a file, store a ticket number and exit. 
---> Write a separate program, to open the file, implement write lock, read the 
ticket  number, increment the number and print the new ticket number then close 
the file.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open(".db", O_RDWR);
    if (fd < 0) {
        perror("error while opening db file: ");
        printf("you might need to run 17_makedb.c first\n");
        return -1;
    }
    struct flock lck;
    lck.l_type = F_WRLCK;
    lck.l_whence = SEEK_SET;
    lck.l_start = 0;
    lck.l_len = 0; // mandatory lock
    lck.l_pid = getpid();
    printf("trying to apply mandatory write lock on db file...\n");
    fcntl(fd, F_SETLKW, &lck);
    struct db
    {
        int ticket_num;
    } item;
    int bytesread = read(fd, &item, sizeof(struct db));
    printf("read ticket number %d from db file (%d bytes)\n", item.ticket_num, bytesread);
    item.ticket_num++;
    lseek(fd, 0, SEEK_SET);
    int wrote = write(fd, &item, sizeof(struct db));
    printf("wrote ticket number %d to db file (%d bytes)\n", item.ticket_num, wrote);
    printf("lock acquired, press enter to release...\n");
    getchar(); // wait for user input
    lck.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lck);
    close(fd);
    printf("write lock released\n");

    return 0;
}