/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       13 August 2024

16. Write a program to perform mandatory locking.
    a. Implement write lock <---
    b. Implement read lock
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char fname[128];
    printf("enter filename to apply write lock on: ");
    scanf("%s", fname);
    int fd = open(fname, O_RDWR);
    if (fd < 0) {
        perror("perror response: ");
        return 1;
    }
    struct flock lck;
    lck.l_type = F_WRLCK;
    lck.l_whence = SEEK_SET;
    lck.l_start = 0;
    lck.l_len = 0; // mandatory lock
    lck.l_pid = getpid();
    printf("trying to apply mandatory write lock on %s...\n", fname);
    fcntl(fd, F_SETLKW, &lck);
    printf("lock acquired, press enter to release...\n");
    read(0, fname, 128); // flush input buffer
    getchar(); // wait for user input
    lck.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lck);
    close(fd);
    printf("write lock released\n");

    return 0;
}

/*
Sample Execution:

$ runc 16a_mand_wr_lock.c
enter filename to apply write lock on: temp.txt
trying to apply mandatory write lock on temp.txt...
lock acquired, press enter to release...

--on second terminal instance:
$ runc 16a_mand_wr_lock.c
enter filename to apply write lock on: temp.txt
trying to apply mandatory write lock on temp.txt...

--press enter on first instance:

write lock released

--on second instance, pressing enter after message:
lock acquired, press enter to release...

write lock released

*/
