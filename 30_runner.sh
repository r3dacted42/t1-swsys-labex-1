#!/bin/bash
# ========================================================================================
# Name:       Priyansh Agrahari
# Reg. No.:   MT2024120
# Date:       22 August 2024

# 30. Write a program to run a script at a specific time using a Daemon process.
# ========================================================================================

cd ~; 
echo "modified by daemon at $(date +%c)" > running.txt
if [ $# -eq 1 ]
then
    echo "i was created at $(date +%c), 30 seconds after the daemon was started" > once.txt
fi

<<sample
Check 30_daemon.c for Sample Execution...
sample
