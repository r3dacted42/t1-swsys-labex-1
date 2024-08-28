/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       22 August 2024

27. Write a program to execute ls -Rl by the following system calls
    a. execl
    b. execlp
    c. execle <---
    d. execv
    e. execvp
========================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    if (!fork()) {
        return execle("/bin/ls", "ls", "-Rl", NULL, __environ);
    }

    wait(0);
    return 0;
}

/*
Sample Execution:

$ runc 27c_execle.c
.:
total 220
-rw-r--r-- 1 r3dacted42 root        1043 Aug 28 14:18 01a_symlink.c
-rw-r--r-- 1 r3dacted42 r3dacted42   945 Aug 28 14:20 01a_symlink.sh
-rw-r--r-- 1 r3dacted42 root        1017 Aug 28 14:19 01b_link.c
-rw-r--r-- 1 r3dacted42 r3dacted42   919 Aug 28 14:22 01b_link.sh
-rw-r--r-- 1 r3dacted42 r3dacted42  1404 Aug 28 14:32 01c_fifo.c
-rw-r--r-- 1 r3dacted42 r3dacted42   902 Aug 28 14:32 01c_fifo.sh
-rw-r--r-- 1 r3dacted42 r3dacted42   367 Aug 28 14:41 02_infloop.c
-rw-r--r-- 1 r3dacted42 r3dacted42  5526 Aug 28 14:35 02_proc.sh
-rw-r--r-- 1 r3dacted42 r3dacted42   841 Aug 28 14:36 03_creat.c
-rw-r--r-- 1 r3dacted42 r3dacted42   952 Aug 28 14:40 04_rdwrt.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1727 Aug 28 14:44 05_checkfd.sh
-rw-r--r-- 1 r3dacted42 r3dacted42   728 Aug 28 14:41 05_copyinf.c
-rw-r--r-- 1 r3dacted42 r3dacted42   944 Aug 28 14:50 06_stdinout.c
-rw-r--r-- 1 r3dacted42 r3dacted42  2342 Aug 28 14:53 07_cp.c
-rw-r--r-- 1 r3dacted42 r3dacted42  4596 Aug 28 14:57 08_readlines.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1478 Aug 28 14:59 09_fileinfo.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1288 Aug 28 15:01 10_rwlseek.c
-rw-r--r-- 1 r3dacted42 r3dacted42  2817 Aug 28 15:03 11_dupfd.c
-rw-r--r-- 1 r3dacted42 r3dacted42   685 Aug 28 15:17 12_openmode.c
-rw-r--r-- 1 r3dacted42 r3dacted42   960 Aug 28 15:19 13_select.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1495 Aug 28 15:23 14_filetype.c
-rw-r--r-- 1 r3dacted42 r3dacted42  3904 Aug 28 15:24 15_environ.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1534 Aug 28 16:08 16a_mand_wr_lock.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1781 Aug 28 16:36 16b_mand_rd_lock.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1154 Aug 28 16:38 17_makedb.c
-rw-r--r-- 1 r3dacted42 r3dacted42  2060 Aug 28 16:40 17_tickets.c
-rw-r--r-- 1 r3dacted42 r3dacted42  5295 Aug 28 16:55 18_record_lock.c
-rw-r--r-- 1 r3dacted42 r3dacted42   569 Aug 28 16:56 19_getpid_time.c
-rw-r--r-- 1 r3dacted42 r3dacted42   877 Aug 28 16:57 20_nice.c
-rw-r--r-- 1 r3dacted42 r3dacted42   556 Aug 28 16:57 21_fork_pid.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1407 Aug 28 16:58 22_fork_write.c
-rw-r--r-- 1 r3dacted42 r3dacted42   829 Aug 28 16:59 23_zombie.c
-rw-r--r-- 1 r3dacted42 r3dacted42   909 Aug 28 17:01 24_orphan.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1707 Aug 28 17:02 25_fav_child.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1196 Aug 28 17:03 26_create_executable.sh
-rw-r--r-- 1 r3dacted42 r3dacted42   561 Aug 28 17:04 26a_run_executable.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1162 Aug 28 17:05 26b_run_input.c
-rw-r--r-- 1 r3dacted42 r3dacted42  3813 Aug 28 17:07 27a_execl.c
-rw-r--r-- 1 r3dacted42 r3dacted42  3810 Aug 28 17:07 27b_execlp.c
-rw-r--r-- 1 r3dacted42 r3dacted42   445 Aug 22 16:34 27c_execle.c
-rw-r--r-- 1 r3dacted42 r3dacted42   464 Aug 22 16:14 27d_execv.c
-rw-r--r-- 1 r3dacted42 r3dacted42   464 Aug 22 16:33 27e_execvp.c
-rw-r--r-- 1 r3dacted42 r3dacted42   529 Aug 22 18:12 28_priority_lims.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1260 Aug 22 18:44 29_sched_policy.c
-rw-r--r-- 1 r3dacted42 r3dacted42  1075 Aug 23 01:31 30_daemon.c
-rw-r--r-- 1 r3dacted42 r3dacted42   358 Aug 23 01:21 30_runner.sh
-rw-r--r-- 1 r3dacted42 r3dacted42  2957 Aug 25 18:40 README.md
-rwxr-xr-x 1 r3dacted42 r3dacted42 16096 Aug 28 17:33 run-1724846603.o
-rw-r--r-- 1 r3dacted42 r3dacted42    30 Aug 22 15:55 temp.txt

*/
