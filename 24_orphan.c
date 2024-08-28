/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

24. Write a program to create an orphan process.
========================================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    int pid = fork();
    if (!pid) {
        // orphan kid
        pid = getpid();
        printf("i'm %d, my parent (%d) will leave me soon :(\n", pid, getppid());
        sleep(2);
        printf("\ni have been adopted by %d :D\nthis is my status (head):\n", getppid());
        char cmd[128];
        sprintf(cmd, "cat /proc/%d/status | head -n 7", pid);
        return system(cmd);
    }
    sleep(1);
    return 0;
}

/*
Sample Execution:

$ runc 24_orphan.c
i'm 261049, my parent (261048) will leave me soon :(
$
i have been adopted by 229069 :D
this is my status (head):
Name:   run-1724844628.
Umask:  0022
State:  S (sleeping)
Tgid:   261049
Ngid:   0
Pid:    261049
PPid:   229069

*/
