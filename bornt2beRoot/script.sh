#!/bin/bash
wall -n \
'#Architecture: ' `hostnamectl | grep "Operating System" | cut -d ' ' -f5- ` '/' `hostnamectl | grep "Kernel" | cut -d ' ' -f14-`
'\n#CPU physical: '`grep physical id /proc/cpuinfo  | wc -l` \
'\n#vCPU:  '`grep processor /proc/cpuinfo | wc -l` \
'\n'`free -mega | awk 'NR==2{printf "#Memory Usage: %s/%sMB (%.2f%%)", $3,$2,$3*100/$2 }'` \
'\n'`df -h | awk '$NF=="/"{printf "#Disk Usage: %d/%dGB (%s)", $3,$2,$5}'` \
$'\n'`top -bn1 | grep load | awk '{printf "#CPU Load: %.2f\n", $(NF-2)}'` \
$'\n#Last boot: ' `who -b | awk '{print $3" "$4" "$5}'` \
$'\n#LVM use: ' `lsblk |grep lvm | awk '{if ($1) {print "yes";exit;} else {print "no"} }'` \
$'\n#Connection TCP:' `ss -t | grep ESTAB | wc -l ` 'ESTABLISHED'\
$'\n#User log: ' `users | wc -w` \
$'\nNetwork: IP ' `hostname -I | awk `{print $1}`"("`ip a | grep link/ether | awk '{print $2}'`")" \
$'\n#Sudo:  ' `journalctl _COMM=sudo | grep COMMAND | wc -l`




The banner is optional. No error must be visible.
		• The architecture of your operating system and its kernel version.
		• The number of physical processors.
		• The number of virtual processors.
		
		• The current available RAM on your server and its utilization rate as a percentage.
		• The current available memory on your server and its utilization rate as a percentage.
		• The current utilization rate of your processors as a percentage.
		• The date and time of the last reboot.
		• Whether LVM is active or not.
		• The number of active connections.
		• The number of users using the server.
		• The IPv4 address of your server and its MAC (Media Access Control) address.
		• The number of commands executed with the sudo program.
