#!/bin/bash

# Name:       Priyansh Agrahari
# Reg. No.:   MT2024120
# Date:       8 August 2024

# 1. Create the following types of a files using (i) shell command (ii) system call
#   a. soft link (symlink system call)
#   b. hard link (link system call)
#   c. FIFO (mkfifo Library Function or mknod system call) <---

echo -n "enter the filename of the fifo pipe: ";
read fname;
if mkfifo $fname
then
    echo "success";
    echo "open the pipe in read mode to get the message";
    echo "hello there, this was written to the fifo pipe!" > $fname
else
    echo "failed";
fi