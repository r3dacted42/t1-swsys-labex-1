/*
========================================================================================
Name:       Priyansh Agrahari
Reg. No.:   MT2024120
Date:       13 August 2024

15. Write a program to display the environmental variable of the 
user (use environ).
========================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("environment variables:\n");
    for (int i = 0; __environ[i] != NULL; i++) {
        printf("\n%s\n", __environ[i]);
    }
    return 0;
}

/*
Sample Execution:

$ runc 15_environ.c
environment variables:

SHELL=/bin/bash

WSL2_GUI_APPS_ENABLED=1

WSL_DISTRO_NAME=Ubuntu

NAME=r3dacted42-LAPTOP

PWD=/home/r3dacted42/t1_swsys/labex_1

LOGNAME=r3dacted42

HOME=/home/r3dacted42

LANG=C.UTF-8

WSL_INTEROP=/run/WSL/229069_interop

LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:

WAYLAND_DISPLAY=wayland-0

LESSCLOSE=/usr/bin/lesspipe %s %s

TERM=xterm-256color

LESSOPEN=| /usr/bin/lesspipe %s

USER=r3dacted42

DISPLAY=:0

SHLVL=2

XDG_RUNTIME_DIR=/run/user/1000/

WSLENV=

XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop

PATH=/home/r3dacted42/.local/bin:/home/r3dacted42/.cargo/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/Program Files/WindowsApps/CanonicalGroupLimited.Ubuntu_2204.3.49.0_x64__79rhkp1fndgsc:/mnt/c/Python312/Scripts/:/mnt/c/Python312/:/mnt/c/Program Files/Eclipse Adoptium/jdk-17.0.7.7-hotspot/bin:/mnt/c/WINDOWS/system32:/mnt/c/WINDOWS:/mnt/c/WINDOWS/System32/Wbem:/mnt/c/WINDOWS/System32/WindowsPowerShell/v1.0/:/mnt/c/WINDOWS/System32/OpenSSH/:/mnt/c/Program Files/NVIDIA Corporation/NVIDIA NvDLISR:/mnt/c/Program Files (x86)/NVIDIA Corporation/PhysX/Common:/mnt/c/Program Files/dotnet/:/mnt/c/Program Files (x86)/Windows Kits/10/Windows Performance Toolkit/:/mnt/c/Program Files/Git/cmd:/mnt/d/sdk/flutter/bin:/mnt/d/sdk/matlab_R2023b/bin:/mnt/c/ProgramData/chocolatey/bin:/mnt/d/sdk/nodejs/:/mnt/c/Program Files/usbipd-win/:/mnt/c/Users/priya/.cargo/bin:/mnt/c/Users/priya/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/priya/AppData/Local/Programs/Microsoft VS Code/bin:/mnt/c/Users/priya/AppData/Local/Android/Sdk/platform-tools:/mnt/c/Users/priya/AppData/Local/Android/Sdk/tools:/mnt/c/Users/priya/AppData/Roaming/npm:/mnt/c/Users/priya/AppData/Local/GitHubDesktop/bin:/mnt/c/Users/priya/.dotnet/tools:/snap/bin

DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus

HOSTTYPE=x86_64

PULSE_SERVER=unix:/mnt/wslg/PulseServer

OLDPWD=/home/r3dacted42

_=./run-1724838843.o

*/
