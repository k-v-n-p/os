#! /usr/bin/bash

read -p "Enter file path or name: " name

if [[ -d $name ]]; then
    echo "$name is a directory"
elif [[ -f $name ]]; then
    echo "$name is a file"
else
    echo "$name is not valid or does not exist"
fi
