/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

28. Write a program to get maximum and minimum real time priority.
*/

#include <sched.h>
#include <stdio.h>

int main(void) {
    printf("round robin:\n  max: %d\n  min: %d\n", 
        sched_get_priority_max(SCHED_RR),
        sched_get_priority_min(SCHED_RR));       
    printf("first in first out (fcfs):\n  max: %d\n  min: %d\n", 
        sched_get_priority_max(SCHED_FIFO),
        sched_get_priority_min(SCHED_FIFO));
    
    return 0;
}

/*
Sample Execution:

$ runc 28_priority_lims.c
round robin:
  max: 99
  min: 1
first in first out (fcfs):
  max: 99
  min: 1

*/
