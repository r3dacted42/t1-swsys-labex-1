/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       13 August 2024

15. Write a program to display the environmental variable of the 
user (use environ).
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("environment variables:\n");
    for (int i = 0; __environ[i] != NULL; i++) {
        printf("\n%s\n", __environ[i]);
    }
    return 0;
}