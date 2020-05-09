#! /bin/bash

mkdir -p outputs
gcc -c test/*.c array.c
gcc -o outputs/test.out *.o
rm -rf *.o
./outputs/test.out