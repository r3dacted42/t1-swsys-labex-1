/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       8 August 2024

1. Create the following types of a files using (i) shell command (ii) system call
  a. soft link (symlink system call) <---
  b. hard link (link system call)
  c. FIFO (mkfifo Library Function or mknod system call)
========================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(void) {
  char fname[128], slname[128];
  printf("enter the filename to create soft link for: ");
  scanf("%s", fname);
  printf("enter the soft link name: ");
  scanf("%s", slname);
  symlink(fname, slname);
  perror("perror response: ");
  
  return 0;
}

/*
Sample Execution:

$ runc 01a_symlink.c
enter the filename to create soft link for: temp.txt
enter the soft link name: tempsl.txt
perror response: : Success

$ ll
total 224
drwxr-xr-x 3 r3dacted42 r3dacted42 4096 Aug 28 14:12 ./
drwxr-xr-x 3 r3dacted42 r3dacted42 4096 Aug 13 15:53 ../
...
-rw-r--r-- 1 r3dacted42 r3dacted42   30 Aug 22 15:55 temp.txt
lrwxrwxrwx 1 r3dacted42 r3dacted42    8 Aug 28 14:12 tempsl.txt -> temp.txt

*/
