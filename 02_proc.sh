#!/bin/bash
# ========================================================================================
# Name:       Priyansh Agrahari
# Reg. No.:   MT2024120
# Date:       8 August 2024

# 2. Write a simple program to execute in an infinite loop at the background. 
# Go to /proc directory and identify all the process related information in 
# the corresponding proc directory.
# ========================================================================================

echo "starting infinte loop c program...";
cc 02_infloop.c -o temp.out;
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

<<sample
Sample Execution:

$ sh 02_proc.sh
starting infinte loop c program...
process running with pid 231315

process status read from proc:
Name:   temp.out
Umask:  0022
State:  R (running)
Tgid:   231315
Ngid:   0
Pid:    231315
PPid:   231309
TracerPid:      0
Uid:    1000    1000    1000    1000
Gid:    1000    1000    1000    1000
FDSize: 64
Groups: 4 20 24 25 27 29 30 44 46 116 1000
NStgid: 231315
NSpid:  231315
NSpgid: 231309
NSsid:  229073
VmPeak:     2672 kB
VmSize:     2644 kB
VmLck:         0 kB
VmPin:         0 kB
VmHWM:       988 kB
VmRSS:       988 kB
RssAnon:              92 kB
RssFile:             896 kB
RssShmem:              0 kB
VmData:       92 kB
VmStk:       132 kB
VmExe:         4 kB
VmLib:      1796 kB
VmPTE:        36 kB
VmSwap:        0 kB
HugetlbPages:          0 kB
CoreDumping:    0
THP_enabled:    1
Threads:        1
SigQ:   1/31437
SigPnd: 0000000000000000
ShdPnd: 0000000000000000
SigBlk: 0000000000000000
SigIgn: 0000000000000006
SigCgt: 0000000000000000
CapInh: 0000000000000000
CapPrm: 0000000000000000
CapEff: 0000000000000000
CapBnd: 000001ffffffffff
CapAmb: 0000000000000000
NoNewPrivs:     0
Seccomp:        0
Seccomp_filters:        0
Speculation_Store_Bypass:       thread vulnerable
SpeculationIndirectBranch:      conditional enabled
Cpus_allowed:   ff
Cpus_allowed_list:      0-7
Mems_allowed:   1
Mems_allowed_list:      0
voluntary_ctxt_switches:        0
nonvoluntary_ctxt_switches:     0

fd's of process:
total 0
lr-x------ 1 r3dacted42 r3dacted42 64 Aug 28 14:34 0 -> /dev/null
lrwx------ 1 r3dacted42 r3dacted42 64 Aug 28 14:34 1 -> /dev/pts/4
lrwx------ 1 r3dacted42 r3dacted42 64 Aug 28 14:34 2 -> /dev/pts/4

contents of process directory:
total 0
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 arch_status
dr-xr-xr-x  2 r3dacted42 r3dacted42 0 Aug 28 14:34 attr
-r--------  1 r3dacted42 r3dacted42 0 Aug 28 14:34 auxv
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 cgroup
--w-------  1 r3dacted42 r3dacted42 0 Aug 28 14:34 clear_refs
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 cmdline
-rw-r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 comm
-rw-r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 coredump_filter
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 cpuset
lrwxrwxrwx  1 r3dacted42 r3dacted42 0 Aug 28 14:34 cwd -> /home/r3dacted42/t1_swsys/labex_1
-r--------  1 r3dacted42 r3dacted42 0 Aug 28 14:34 environ
lrwxrwxrwx  1 r3dacted42 r3dacted42 0 Aug 28 14:34 exe -> /home/r3dacted42/t1_swsys/labex_1/temp.out
dr-x------  2 r3dacted42 r3dacted42 0 Aug 28 14:34 fd
dr-xr-xr-x  2 r3dacted42 r3dacted42 0 Aug 28 14:34 fdinfo
-rw-r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 gid_map
-r--------  1 r3dacted42 r3dacted42 0 Aug 28 14:34 io
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 limits
-rw-r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 loginuid
dr-x------  2 r3dacted42 r3dacted42 0 Aug 28 14:34 map_files
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 maps
-rw-------  1 r3dacted42 r3dacted42 0 Aug 28 14:34 mem
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 mountinfo
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 mounts
-r--------  1 r3dacted42 r3dacted42 0 Aug 28 14:34 mountstats
dr-xr-xr-x 65 r3dacted42 r3dacted42 0 Aug 28 14:34 net
dr-x--x--x  2 r3dacted42 r3dacted42 0 Aug 28 14:34 ns
-rw-r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 oom_adj
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 oom_score
-rw-r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 oom_score_adj
-r--------  1 r3dacted42 r3dacted42 0 Aug 28 14:34 pagemap
-r--------  1 r3dacted42 r3dacted42 0 Aug 28 14:34 personality
-rw-r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 projid_map
lrwxrwxrwx  1 r3dacted42 r3dacted42 0 Aug 28 14:34 root -> /
-rw-r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 sched
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 schedstat
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 sessionid
-rw-r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 setgroups
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 smaps
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 smaps_rollup
-r--------  1 r3dacted42 r3dacted42 0 Aug 28 14:34 stack
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 stat
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 statm
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 status
-r--------  1 r3dacted42 r3dacted42 0 Aug 28 14:34 syscall
dr-xr-xr-x  3 r3dacted42 r3dacted42 0 Aug 28 14:34 task
-rw-r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 timens_offsets
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 timers
-rw-rw-rw-  1 r3dacted42 r3dacted42 0 Aug 28 14:34 timerslack_ns
-rw-r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 uid_map
-r--r--r--  1 r3dacted42 r3dacted42 0 Aug 28 14:34 wchan

killing infinite loop...
killed, exiting

sample
