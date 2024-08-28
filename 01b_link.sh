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

<<sample
Sample Execution:

$ sh 01b_link.sh
enter the path to create hard link for: temp.txt
enter the hard link name: temphl1.txt
success

$ ll
total 224
drwxr-xr-x 3 r3dacted42 r3dacted42 4096 Aug 28 14:17 ./
drwxr-xr-x 3 r3dacted42 r3dacted42 4096 Aug 13 15:53 ../
...
-rw-r--r-- 2 r3dacted42 r3dacted42   30 Aug 22 15:55 temp.txt
-rw-r--r-- 2 r3dacted42 r3dacted42   30 Aug 22 15:55 temphl1.txt

sample
