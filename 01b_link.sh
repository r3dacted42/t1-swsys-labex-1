#!/bin/bash

# Name:       Priyansh Agrahari
# Reg. No.:   MT2024120
# Date:       8 August 2024

# 1. Create the following types of a files using (i) shell command (ii) system call
#   a. soft link (symlink system call)
#   b. hard link (link system call) <---
#   c. FIFO (mkfifo Library Function or mknod system call)

echo -n "enter the path to create hard link for: ";
read fname;
echo -n "enter the hard link name: ";
read hlname;
if ln $fname $hlname
then
    echo "success";
else
    echo "failed";
fi