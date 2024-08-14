#!/bin/bash

# Name:       Priyansh Agrahari
# Reg. No.:   MT2024120
# Date:       8 August 2024

# 1. Create the following types of a files using (i) shell command (ii) system call
#   a. soft link (symlink system call) <---
#   b. hard link (link system call)
#   c. FIFO (mkfifo Library Function or mknod system call)

echo -n "enter the filename to create soft link for: ";
read fname;
echo -n "enter the soft link name: ";
read slname;
if ln -s $fname $slname
then
    echo "success";
else
    echo "failed";
fi