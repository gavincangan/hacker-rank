#!/bin/bash

cpp_file_to_build=$1
output_file=$(pwd)/${cpp_file_to_build/\.cpp/\.o}

rename_output_file=$(pwd)/zz_${cpp_file_to_build/\.cpp/\.o}ld

mv $output_file $rename_output_file

# echo cpp_file_to_build = $cpp_file_to_build 
# echo output_file = $output_file

g++ -g -std=gnu++14 -Wall $cpp_file_to_build -o $output_file;

if [ -f $output_file ]; then

    if [ -z "$2" ]
    then
        $output_file;
    else
        cat $2 | $output_file;
    fi

else
    echo Output binary not found! Build must have failed!
fi;
