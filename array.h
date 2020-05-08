#ifndef __ARRAY_H
#define __ARRAY_H

typedef enum
{
  False,
  True
} Bool;

typedef int *Int_ptr;
typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef struct
{
  int *array;
  int length;
} Array;

typedef Array *Array_ptr;

Array_ptr init_array(Int_ptr array, int length);

Array_ptr map(Array_ptr src, Mapper mapper);
Array_ptr filter(Array_ptr src, Predicate predicate);
int reduce(Array_ptr src, int init, Reducer reducer);

#endif
