#!/bin/bash

file_path=(`find . -name *txt`)
echo $file_path
cp -rvf $file_path ./aa.txt
