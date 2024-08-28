#!/bin/bash
# ========================================================================================
# Name:       Priyansh Agrahari
# Reg. No.:   MT2024120
# Date:       8 August 2024

# 5. Write a program to create five new files with infinite loop. 
# Execute the program in the background and check the file descriptor 
# table at /proc/pid/fd.
# ========================================================================================

echo "starting c program to create 5 copies of inf loop program...";
cc 05_copyinf.c -o temp.out;
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
    for n in $(seq 0 4);
    do
        rm -f inf_$n.c
        echo "deleted inf_$n.c..."
    done
else
    echo "failed to kill";
fi

<<sample
Sample Execution:

$ sh 05_checkfd.sh
starting c program to create 5 copies of inf loop program...
process running with pid

list of files in /proc/232990/fd:
total 0
lr-x------ 1 r3dacted42 r3dacted42 64 Aug 28 14:42 0 -> /dev/null
lrwx------ 1 r3dacted42 r3dacted42 64 Aug 28 14:42 1 -> /dev/pts/4
lrwx------ 1 r3dacted42 r3dacted42 64 Aug 28 14:42 2 -> /dev/pts/4
l-wx------ 1 r3dacted42 r3dacted42 64 Aug 28 14:42 3 -> /home/r3dacted42/t1_swsys/labex_1/inf_0.c
l-wx------ 1 r3dacted42 r3dacted42 64 Aug 28 14:42 4 -> /home/r3dacted42/t1_swsys/labex_1/inf_1.c
l-wx------ 1 r3dacted42 r3dacted42 64 Aug 28 14:42 5 -> /home/r3dacted42/t1_swsys/labex_1/inf_2.c
l-wx------ 1 r3dacted42 r3dacted42 64 Aug 28 14:42 6 -> /home/r3dacted42/t1_swsys/labex_1/inf_3.c
l-wx------ 1 r3dacted42 r3dacted42 64 Aug 28 14:42 7 -> /home/r3dacted42/t1_swsys/labex_1/inf_4.c

killing c program...
killed, exiting
deleted inf_0.c...
deleted inf_1.c...
deleted inf_2.c...
deleted inf_3.c...
deleted inf_4.c...

sample
