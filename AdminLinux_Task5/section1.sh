#!/bin/bash
sudo adduser esraa
sudo groupadd -r ghita
if grep "^esraa:" /etc/passwd ; then 
	echo "The user esraa exists"
else
	echo "The user esraa doesn't exist"
fi

if grep "^ghita" /etc/group ; then
	echo "The group ghita exists"
else 
	echo "The group ghita doesn't exist"
fi
echo "The User esraa Information is: "
lslogins esraa
echo "The Group ghita Infomation is: "
getent group ghita
sudo usermod -aG ghita esraa
echo "The User esraa Information is: "
lslogins esraa
echo "The Group ghita Information is: "
getent group ghita
