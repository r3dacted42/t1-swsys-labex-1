/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       23 August 2024

30. Write a program to run a script at a specific time using a Daemon process.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int init_daemon() {
    int pid = fork();
    if (pid > 0) return 0;
    if (pid < 0) return -1;
    pid = getpid();

    setsid();
    umask(0);
    int fd = open(".log", O_RDWR | O_CREAT | O_APPEND, 0777);
    char msg[128] = {0};
    sprintf(msg, "[%d] daemon started at %ld\n", pid, time(NULL));
    write(fd, msg, sizeof(msg));
    long int init_time = time(NULL);
    while (1) {
        sprintf(msg, "[%d] daemon still running at %ld\n", pid, time(NULL));
        write(fd, msg, sizeof(msg));
        system("sh 30_runner.sh");
        sleep(10);
        if (init_time > 0 && time(NULL) - init_time > 30) {
            system("sh 30_runner.sh hehe");
            init_time = -1;
        }
    }
    return 0;    
}

int main(void) {
    return init_daemon();
}

/*
Sample Execution:

$ runc 30_daemon.c
((no output on terminal))

--after some time:
$ cat .log
[264390] daemon started at 1724847831
[264390] daemon still running at 1724847831
[264390] daemon still running at 1724847841
[264390] daemon still running at 1724847851
[264390] daemon still running at 1724847861
[264390] daemon still running at 1724847871
[264390] daemon still running at 1724847881
[264390] daemon still running at 1724847891
[264390] daemon still running at 1724847901
[264390] daemon still running at 1724847911
[264390] daemon still running at 1724847921
[264390] daemon still running at 1724847931
[264390] daemon still running at 1724847941

$ cat ~/running.txt
modified by daemon at Wed Aug 28 17:56:01 2024

$ cat ~/once.txt
i was created at Wed Aug 28 17:54:31 2024, 30 seconds after the daemon was started

$ kill 264390
((terminate the daemon))

*/
