#!/bin/bash

# Name:       Priyansh Agrahari
# Reg. No.:   MT2024120
# Date:       8 August 2024

# 5. Write a program to create five new files with infinite loop. 
# Execute the program in the background and check the file descriptor 
# table at /proc/pid/fd.

echo "starting c program to create 5 copies of inf loop program...";
cc 5_copyinf.c -o temp.out;
./temp.out &
pid=$!
echo "process running with pid $pidn";
echo;
echo "list of files in /proc/$pid/fd:";
ls -l /proc/$pid/fd;

echo;
echo "killing c program...";
if kill $pid;
then
    echo "killed, exiting";
    rm temp.out
    for n in {0..4};
    do
        rm -f inf_$n.c
    done
else
    echo "failed to kill";
fi