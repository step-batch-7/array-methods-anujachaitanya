#! /bin/bash

if [[ ! -d outputs ]]; then
  mkdir outputs;
fi
 gcc -c test/*.c array.c
 gcc -o outputs/test.out *.o
 ./outputs/test.out
 rm -rf *.o