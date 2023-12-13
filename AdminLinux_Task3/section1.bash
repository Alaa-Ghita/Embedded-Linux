#!/bin/bash
if [ -f ~/.bashrc ]
then 
	export HELLO=HOSTNAME 
	LOCAL=whoami 
fi 
gnome-terminal 

