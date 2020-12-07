#! /usr/bin/bash

echo "enter number of files to be reanamed"
read num;
for i in $(seq 1 $num)
do 
	read -p "Enter the original file name: " org
	if [[ ! -f $org ]]; then
		echo "$org filename doesn't not exist."
	else
		read -p "Enter the new file name: " new
		if  [[ -f $new ]]; then
			echo "File with that name already exists." 
			#decrement i if wanted here by adding..i=$((i-1))
		else
			mv $org $new
			if [[ -f $new ]]; then 
				echo "File name changed sucessfully."
			fi;
		fi;
	fi;
done
