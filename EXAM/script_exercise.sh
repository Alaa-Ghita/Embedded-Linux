echo $USER
echo $HOSTNAME
mkdir ~/script_exercise
cd ~/script_exercise
for i in 1 2 3 4 5
do 
	touch file$i.txt
done
for i in 1 2 3 4 5
do 
	date >> file$i.txt
done
for i in 1 2 3 4 5 
do 
	cat file$i.txt
done
