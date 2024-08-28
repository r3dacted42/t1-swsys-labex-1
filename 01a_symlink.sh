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

<<sample
Sample Execution:

$ sh 01a_symlink.sh
enter the filename to create soft link for: temp.txt
enter the soft link name: tempsl1.txt
success

$ ll
total 224
drwxr-xr-x 3 r3dacted42 r3dacted42 4096 Aug 28 14:17 ./
drwxr-xr-x 3 r3dacted42 r3dacted42 4096 Aug 13 15:53 ../
...
-rw-r--r-- 1 r3dacted42 r3dacted42   30 Aug 22 15:55 temp.txt
lrwxrwxrwx 1 r3dacted42 r3dacted42    8 Aug 28 14:17 tempsl1.txt -> temp.txt

sample
