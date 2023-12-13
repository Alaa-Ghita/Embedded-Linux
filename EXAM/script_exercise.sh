mkdir ~/script_exercise
cd ~/script_exercise
touch file1.txt file2.txt file3.txt file4.txt file5.txt
date >> file1.txt
date >> file2.txt
date >> file3.txt
date >> file4.txt
date >> file5.txt
for i in 1 2 3 4 5 
do 
	cat file$i.txt
done
