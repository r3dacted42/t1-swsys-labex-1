/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       8 August 2024

1. Create the following types of a files using (i) shell command (ii) system call
  a. soft link (symlink system call)
  b. hard link (link system call)
  c. FIFO (mkfifo Library Function or mknod system call) <---
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <linux/stat.h>

// add prototype to prevent warning :)
int mkfifo(const char *pathname, mode_t mode);

int main(void) {
  char fname[128];
  printf("enter the filename of the fifo pipe: ");
  scanf("%s", fname);
  mkfifo(fname, 0777);
  perror("perror response: ");
  printf("open the fifo pipe in read mode and press enter to continue...\n");
  getchar();
  int fifo_fd = open(fname, O_WRONLY);
  char msg[] = "hello there, this was written to the fifo pipe!";
  int count = write(fifo_fd, msg, sizeof(msg)/sizeof(char));
  close(fifo_fd);
  printf("%d characters written to pipe\n", count);
  
  return 0;
}
