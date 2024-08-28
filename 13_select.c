/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       13 August 2024

13. Write a program to wait for a STDIN for 10 seconds using select. 
Write a proper print statement to verify whether the data is available 
within 10 seconds or not (check in $man 2 select).
========================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <time.h>

int main(void) {
    fd_set set;
    FD_ZERO(&set);
    FD_SET(0, &set);

    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    int result = select(1, &set, NULL, NULL, &timeout);

    char buf[128];
    if (result) {
        scanf("%[^\n]", buf);
        printf("data found within 10 seconds! read: %s\n", buf);
    } else {
        printf("data not found within 10 seconds\n");
    }

    return 0;
}

/*
Sample Execution:

$ runc 13_select.c
hehe
data found within 10 seconds! read: hehe

--on not entering data
$ runc 13_select.c
data not found within 10 seconds

*/