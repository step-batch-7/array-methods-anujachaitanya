#! /bin/bash

if [[ ! -d bin ]]; then
  mkdir bin;
fi
 gcc -c test/*.c array.c
 gcc -o bin/test.out *.o
 ./bin/test.out
 rm -rf *.o