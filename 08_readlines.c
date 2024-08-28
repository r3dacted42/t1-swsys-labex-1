/*
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       10 August 2024

8. Write a program to open a file in read only mode, read line by line 
and display each line as it is read. Close the file when end of file 
is reached.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 128

int main(void) {
    char fname[128];
    printf("enter filename to read: ");
    scanf("%s", fname);
    int fd = open(fname, O_RDONLY);
    if (fd == -1) {
        perror("perror response: ");
        return 1;
    }
    char buf[BUF_SIZE];
    for (int i = 0, bytesread = 1, foundEOL = 1; bytesread > 0; ) {
        bytesread = read(fd, buf, BUF_SIZE);
        if (bytesread) {
            int written = 0;
            do {
                int lineend = written - 1, lineidx = 0;
                char linebuf[BUF_SIZE];
                while (buf[++lineend] != '\n' && lineend < bytesread && lineidx < BUF_SIZE - 1) 
                    linebuf[lineidx++] = buf[lineend];
                linebuf[lineidx] = '\0';
                if (foundEOL) printf("\n%d: %s", i++, linebuf);
                else printf("%s", linebuf);
                foundEOL = (buf[lineend] == '\n');
                written += lineidx + 1;
            } while(written < bytesread);
        }
        for (int i = 0; i < BUF_SIZE; i++) buf[i] = 0;
    }
    printf("\n");
    close(fd);
    
    return 0;
}

/*
Sample Execution:

$ runc 08_readlines.c
enter filename to read: README.md

0: # lab exercises 1
1: cs513 software systems; term 1, 2024-26
2:
3: ## instructions to run
4:
5: it is recommended to use the following script to run the C programs:
6: ```bash
7: #!/bin/bash
8:
9: args=""
10: for i in $(seq 2 $#)
11: do
12:         argi=${!i}
13:         args="$args $argi"
14: done
15: exe="run-$(date +%s).o"
16: if gcc $1 -o $exe
17: then
18:         ./$exe $args
19:         rm $exe
20: fi
21: ```
22: save the script as runc.sh and use `chmod u+x runc.sh` to allow it to function properly. additionally, you can add the line `alias runc='<path-to-runc.sh>'` to th `~/.bashrc` file to use the script from any directory. don't forget to use a fresh terminal instance after editing `~/.bashrc`
23:
24: to run any C program, use
25: `runc <filename.c> <additional-args-here>`
26:
27: ## other remarks
28:
29: - most programs are interactive and will require you to enter the prompted information during runtime
30: - for task 1, two files exist for each task, one for bash and C each. both of them are equivalent in functioning
31: - for task 2, running `02_proc.sh` will start the C program in `02_infloop.c` and display the required data, after which it will kill the inf loop and exit
32: - for task 5, running `05_checkfd.sh` will start the C program in `05_copyinf.c` which will in turn create 5 copies of the infinite loop program file `02_infloop.c` and stay stuc in an infinite loop and wait for the sweet release of death. the bash script will display the required data and kill the previusly started C program
33: - for task 7, it is possible to supply the source and destination file names in the run command as in `runc 07_cp.c srcfile dstfile`. alternatively, the program will prompt for the filenames if not given as cmd line args
34: - for task 11, parts a, b and c are combined into a single file
35: - for task 14, providing the filename as cmd line arg is required, as in `runc 14_filetype.c <filename>`
36: - for tasks 16, 17 and 18, verification of the locks can be done by using the previously described `runc` command in different shell instances
37: - however, for task 17, `17_makedb.c` must be run before `17_tickets.c` to make sure the 'database' file `./.db` exists. similarly, task 18 uses a file called `./.db1` for storing the records
38: - task 18 requires several bits of input, but sometimes the input buffer has leftover newline characters that mess with the program. to deal with tat, additional `getchar()` calls are placed at appropriate locations to clear the buffer
39: - for task 26, you must run `26_create_executable.sh` before running the other parts
40: - for task 29, failure occurs if su privileges are not provided
41: - task 30 starts a daemon that runs without a terminal window (orphan process), and prints a log message with the pid in `./.log` every 10 second. it also executes `30_runner.sh` every 10 seconds which creates and modifies 2 txt files in the user home directory. `~/runnin.txt` is updated every 10 seconds, and `~/once.txt` is created once after 30 seconds have passed since the daemon was started.
42:
43: thank you
44:

*/
