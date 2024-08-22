/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

26. Write a program to execute an executable program.
    a. use some executable program <---
    b. pass some input to an executable program. (for example execute an 
       executable of $./a.out name)
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char cmdargs[128], exin[128];
    printf("cmd line arguments to pass to executable: ");
    scanf("%[^\n]", cmdargs);
    getchar(); // remove \n from buffer
    printf("input to pass to stdin of executable: ");
    scanf("%[^\n]", exin);
    getchar(); // remove \n from buffer
    putchar('\n');
    char cmd[284];
    sprintf(cmd, "echo \"%s\" | ./26_executable.o %s", exin, cmdargs);
    int r = system(cmd);
    if (r != 0) {
        printf("error while executing program\n");
    }
    return 0;
}