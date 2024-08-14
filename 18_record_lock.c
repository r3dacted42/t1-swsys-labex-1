/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       13 August 2024

18. Write a program to perform Record locking.
    a. Implement write lock
    b. Implement read lock
Create three records in a file. Whenever you access a particular record, 
first lock it then modify/access to avoid race condition.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct db {
    int id;
    char data[128];
} record;

void init_records(int fd) {
    record records[3];
    for (int i = 0; i < 3; i++) records[i].id = i + 1;
    sprintf(records[0].data, "first entry");
    sprintf(records[1].data, "second entry");
    sprintf(records[2].data, "third entry");
    int prevpos = lseek(fd, 0, SEEK_CUR);
    lseek(fd, 0, SEEK_SET);
    for (int i = 0; i < 3; i++) {
        write(fd, &records[i], sizeof(record));
    }
    lseek(fd, prevpos, SEEK_SET);
}

// void flush_stdin() {
//     char buf[1];
//     while (read(0, buf, 1)) {
//         if (buf[0] != '\n' && buf[0] != '\0') {
//             ungetc(buf[0], stdin);
//             break;
//         }
//     }
// }

int main(void) {
    int fd = open(".db1", O_RDWR);
    if (fd < 0) {
        fd = creat(".db1", 0777);
        init_records(fd);
    }
    char ch = '\0';
    while (ch != 'q') {
        int rec_idx = -1;
        printf("which record would you like to access/modify? [1, 2, 3]\n");
        // ch = getchar();
        // rec_idx = ch - 48; // ascii -> integer value
        scanf("%d", &rec_idx);
        getchar(); // remove \n?
        if (rec_idx < 1 || rec_idx > 3) {
            printf("please select a valid record index!\n\n");
            continue;
        }
        printf("you selected record %d, would you like to view [v] contents or modify [m]?\n", rec_idx);
        scanf("%c", &ch);
        getchar(); // remove \n again? :|
        if (ch == 'v') {
            printf("trying to acquire read lock for record %d...\n", rec_idx);
            struct flock rd_lock;
            rd_lock.l_type = F_RDLCK;
            rd_lock.l_start = (rec_idx - 1) * sizeof(record);
            rd_lock.l_len = sizeof(record);
            rd_lock.l_whence = SEEK_SET;
            rd_lock.l_pid = getpid();
            fcntl(fd, F_SETLKW, &rd_lock);
            printf("acquired read lock for record %d!\n", rec_idx);
            lseek(fd, (rec_idx - 1) * sizeof(record), SEEK_SET);
            record rec;
            int bytesread = read(fd, &rec, sizeof(record));
            printf("read %d bytes:\n", bytesread);
            printf("  id:   %d\n", rec.id);
            printf("  data: %s\n", rec.data);
            printf("press enter to release read lock...\n");
            getchar();
            rd_lock.l_type = F_UNLCK;
            fcntl(fd, F_SETLK, &rd_lock);
            printf("read lock released.\n");
        } else if (ch == 'm') {
            printf("trying to acquire write lock for record %d...\n", rec_idx);
            struct flock wr_lock;
            wr_lock.l_type = F_WRLCK;
            wr_lock.l_start = (rec_idx - 1) * sizeof(record);
            wr_lock.l_len = sizeof(record);
            wr_lock.l_whence = SEEK_SET;
            wr_lock.l_pid = getpid();
            fcntl(fd, F_SETLKW, &wr_lock);
            printf("acquired read lock for record %d!\n", rec_idx);
            record rec;
            rec.id = rec_idx;
            printf("enter the new data for record %d:\n", rec_idx);
            scanf("%[^\n]", rec.data);
            getchar(); // remove \n :D
            lseek(fd, (rec_idx - 1) * sizeof(record), SEEK_SET);
            int byteswritten = write(fd, &rec, sizeof(record));
            printf("wrote %d bytes.\n", byteswritten);
            printf("press enter to release write lock...\n");
            getchar();
            wr_lock.l_type = F_UNLCK;
            fcntl(fd, F_SETLK, &wr_lock);
            printf("write lock released.\n");
        } else {
            printf("please enter a valid choice!\n\n");
            ch = '\0';
            continue;
        }
        printf("enter [q] to quit or [c] to continue: ");
        ch = getchar();
    }
    close(fd);
}