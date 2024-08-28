/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

19. Write a program to find out time taken to execute getpid system call. 
Use time stamp counter.
*/

#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main(void) {
    time_t start, end;
    start = clock();
    int pid = getpid();
    end = clock();
    double diff = end - start;
    printf("getpid() took %lf seconds\n", (diff / CLOCKS_PER_SEC));

    return 0;
}

/*
Sample Execution:

$ runc 19_getpid_time.c
getpid() took 0.000001 seconds

*/
