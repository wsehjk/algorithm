#! /bin/bash 
rm *.class > /dev/null 2>&1
JAVAS=$(ls *.java)
# echo $JAVAS

# for file in $JAVAS;
# do
#     echo $file
#     javac-algs4 $file
# done

file=$1
EXEC_PARAMS=($@)
EXEC_PARAMS=${EXEC_PARAMS[@]:1:2}
javac-algs4 $file 
file=$(echo "${file%%.*}")

echo -e "\033[33mbinary is $file\033[0m"
echo -e "\033[33mparas is $EXEC_PARAMS\033[0m"

java-algs4 $file $EXEC_PARAMS