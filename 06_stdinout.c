/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       10 August 2024

6. Write a program to take input from STDIN and display on STDOUT. 
Use only read/write system calls.
========================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int _printstr(const char s[], int maxsize) {
    int actualsize = 0;
    while (s[++actualsize] != '\0' && actualsize < maxsize);
    return write(1, s, actualsize);
}

int _read(char *s, int size) {
    int r = read(0, s, size);
    s[r] = '\0';
    return r;
}

int main(void) {
    char msg[] = "please enter some text: ";
    _printstr(msg, sizeof(msg) / sizeof(char));
    char inp[128];
    _read(inp, 128);
    char msg1[] = "you entered: ";
    _printstr(msg1, sizeof(msg1) / sizeof(char));
    _printstr(inp, sizeof(inp) / sizeof(char));
    return 0;
}

/*
Sample Execution:

$ runc 06_stdinout.c
please enter some text: eternal torment hehe :)
you entered: eternal torment hehe :)

*/
