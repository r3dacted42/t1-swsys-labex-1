#!/bin/bash

# Name:       Priyansh Agrahari
# Reg. No.:   MT2024120
# Date:       8 August 2024

# 2. Write a simple program to execute in an infinite loop at the background. 
# Go to /proc directory and identify all the process related information in 
# the corresponding proc directory.

echo "starting infinte loop c program...";
cc 2_infloop.c -o temp.out;
./temp.out &
pid=$!
echo "process running with pid $pid\n";
echo "process status read from proc:";
cat /proc/$pid/status;
echo "\nfd's of process:";
ls -l /proc/$pid/fd/;
echo "\ncontents of process directory:";
ls -l /proc/$pid/;

echo "\nkilling infinite loop...";
if kill $pid;
then
    echo "killed, exiting";
    rm temp.out
else 
    echo "failed to kill";
fi