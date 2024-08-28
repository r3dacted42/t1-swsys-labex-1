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

int main(void) {
    int fd = open(".db1", O_RDWR);
    if (fd < 0) {
        fd = creat(".db1", 0777);
        init_records(fd);
        close(fd);
        fd = open(".db1", O_RDWR);
    }
    char ch = '\0';
    while (ch != 'q') {
        int rec_idx = -1;
        printf("which record would you like to access/modify? [1, 2, 3]\n");
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
            printf("acquired write lock for record %d!\n", rec_idx);
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
        close(fd);
        fd = open(".db1", O_RDWR);
    }
    close(fd);
}

/*
Sample Execution:

--first instance:
$ runc 18_record_lock.c
which record would you like to access/modify? [1, 2, 3]
2
you selected record 2, would you like to view [v] contents or modify [m]?
m
trying to acquire write lock for record 2...
acquired write lock for record 2!
enter the new data for record 2:
sample data for record two
wrote 132 bytes.
press enter to release write lock...

--second instance:
$ runc 18_record_lock.c 
which record would you like to access/modify? [1, 2, 3]
1
you selected record 1, would you like to view [v] contents or modify [m]?
m
trying to acquire write lock for record 1...
acquired write lock for record 1!
enter the new data for record 1:
other sample data for record one
wrote 132 bytes.
press enter to release write lock...

--third instance:
$ runc 18_record_lock.c
which record would you like to access/modify? [1, 2, 3]
2
you selected record 2, would you like to view [v] contents or modify [m]?
v
trying to acquire read lock for record 2...

--third instance after releasing write lock from first instance:
acquired read lock for record 2!
read 132 bytes:
  id:   2
  data: sample data for record two
press enter to release read lock...

((concurrent viewing/editing for different records is allowed, 
but writing to the same record or viewing a record while it is 
being edited in another instance is prohibited.))

*/
