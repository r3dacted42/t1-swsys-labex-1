# lab exercises 1
cs513 software systems; term 1, 2024-26  

## instructions to run

it is recommended to use the following script to run the C programs:
```bash
#!/bin/bash

args=""
for i in $(seq 2 $#)
do
        argi=${!i}
        args="$args $argi"
done
exe="run-$(date +%s).o"
if gcc $1 -o $exe
then
        ./$exe $args
        rm $exe
fi
```
save the script as runc.sh and use `chmod u+x runc.sh` to allow it to function properly. additionally, you can add the line `alias runc='<path-to-runc.sh>'` to the `~/.bashrc` file to use the script from any directory. don't forget to use a fresh terminal instance after editing `~/.bashrc`!

to run any C program, use
`runc <filename.c> <additional-args-here>`

## other remarks

- most programs are interactive and will require you to enter the prompted information during runtime
- for task 1, two files exist for each task, one for bash and C each. both of them are equivalent in functioning
- for task 2, running `02_proc.sh` will start the C program in `02_infloop.c` and display the required data, after which it will kill the inf loop and exit
- for task 5, running `05_checkfd.sh` will start the C program in `05_copyinf.c` which will in turn create 5 copies of the infinite loop program file `02_infloop.c` and stay stuck in an infinite loop and wait for the sweet release of death. the bash script will display the required data and kill the previously started C program
- for task 7, it is possible to supply the source and destination file names in the run command as in `runc 07_cp.c srcfile dstfile`. alternatively, the program will prompt for the filenames if not given as cmd line args
- for task 11, parts a, b and c are combined into a single file
- for task 14, providing the filename as cmd line arg is required, as in `runc 14_filetype.c <filename>`
- for tasks 16, 17 and 18, verification of the locks can be done by using the previously described `runc` command in different shell instances
- however, for task 17, `17_makedb.c` must be run before `17_tickets.c` to make sure the 'database' file `.db` exists. similarly, task 18 uses a file called `.db1` for storing the records
- task 18 requires several bits of input, but sometimes the input buffer has leftover newline characters that mess with the program. to deal with that, additional `getchar()` calls are placed at appropriate locations to clear the buffer
- for task 26, you must run `26_create_executable.sh` before running the other parts
- for task 29, failure occurs if su privileges are not available
- task 30 starts a daemon that runs without a terminal window (orphan process), and prints a log message with the pid in `.log` every 10 seconds. it also executes `30_runner.sh` every 10 seconds which creates and modifies 2 txt files in the user home directory. `running.txt` is updated every 10 seconds, and `once.txt` is created once after 30 seconds have passed since the daemon was started.
  
thank you