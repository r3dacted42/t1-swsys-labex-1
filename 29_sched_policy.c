/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

29. Write a program to get scheduling policy and modify the scheduling policy 
(SCHED_FIFO, SCHED_RR).
========================================================================================
*/

#include <sched.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    int pid = getpid(), curr_sched = sched_getscheduler(pid);
    char policy_name[32];
    switch (curr_sched) {
        case SCHED_OTHER:   sprintf(policy_name, "rr time-sharing"); break;
        case SCHED_FIFO:    sprintf(policy_name, "fifo"); break;
        case SCHED_RR:      sprintf(policy_name, "round robin"); break;
    }
    printf("current scheduling policy is %s\n", policy_name);

    printf("select a policy to apply to current process:\n");
    printf("  0 : fifo\n  1 : round robin\n");
    int choice;
    scanf("%d", &choice);
    if (choice < 0 || choice > 1) {
        printf("invalid option, please enter 0 or 1\n");
        return -1;
    }
    struct sched_param p;
    p.sched_priority = 42;
    if (sched_setscheduler(pid, (choice ? SCHED_RR : SCHED_FIFO), &p)) {
        perror("sched_setscheduler failed with: ");
        return -1;
    } else {
        printf("scheduling policy successfully set to %s\n", (choice ? "round robin" : "fifo"));
    }

    return 0;
}

/*
Sample Execution:

$ runc 29_sched_policy.c
current scheduling policy is rr time-sharing
select a policy to apply to current process:
  0 : fifo
  1 : round robin
1
sched_setscheduler failed with: : Operation not permitted

$ gcc 29_sched_policy.c -o temp.o
$ sudo ./temp.o
[sudo] password for r3dacted42:
current scheduling policy is rr time-sharing
select a policy to apply to current process:
  0 : fifo
  1 : round robin
1
scheduling policy successfully set to round robin

*/
