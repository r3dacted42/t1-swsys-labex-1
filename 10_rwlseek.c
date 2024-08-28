/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       13 August 2024

10. Write a program to open a file with read write mode, write 10 bytes, move 
the file pointer by 10 bytes (use lseek) and write again 10 bytes.
    a. check the return value of lseek
    b. open the file with od and check the empty spaces in between the data.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void) {
    char fname[128];
    printf("enter the name of a file to write to: ");
    scanf("%s", fname);
    int fd = open(fname, O_CREAT | O_RDWR, 0666);
    if (fd < 0) {
        perror("perror response: ");
        return 0;
    }
    char filler[] = "pipo-pipo!";
    write(fd, filler, 10);
    int lret = lseek(fd, 10, SEEK_CUR);
    write(fd, filler, 10);
    close(fd);
    
    printf("return value of lseek: %d\n", lret);
    printf("output of od command:\n");
    char cmd[5 + 128];
    sprintf(cmd, "od %s", fname);
    return system(cmd);
}

/*
Sample Execution:

$ runc 10_rwlseek.c
enter the name of a file to write to: tempseek.c
return value of lseek: 20
output of od command:
0000000 064560 067560 070055 070151 020557 000000 000000 000000
0000020 000000 000000 064560 067560 070055 070151 020557
0000036

*/
