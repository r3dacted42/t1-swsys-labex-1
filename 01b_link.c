/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       8 August 2024

1. Create the following types of a files using (i) shell command (ii) system call
  a. soft link (symlink system call)
  b. hard link (link system call) <---
  c. FIFO (mkfifo Library Function or mknod system call)
*/

#include <stdio.h>
#include <unistd.h>

int main(void) {
  char fname[128], hlname[128];
  printf("enter the path to create hard link for: ");
  scanf("%s", fname);
  printf("enter the hard link name: ");
  scanf("%s", hlname);
  link(fname, hlname);
  perror("perror response: ");
  
  return 0;
}
