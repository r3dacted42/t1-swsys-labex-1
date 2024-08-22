/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

20. Find out the priority of your running program. 
Modify the priority with nice command.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

// prototypes
int getrlimit(int resource, struct rlimit *rlim);
int nice(int inc);

int main(void) {
    struct rlimit lim;
    int r = getrlimit(RLIMIT_NICE, &lim);
    if (r != 0) {
        perror("getrlimit failed with: ");
        return 0;
    }
    printf("soft limit for RLIMIT_NICE is %lu\n", 20 - lim.rlim_cur);
    int current = nice(0);
    printf("current priority is %d\n", current);
    int on_set = nice(5);
    printf("priority after +5 is %d\n", on_set);

    return 0;
}