#ifndef __ARRAY_VOID_H
#define __ARRAY_VOID_H

#include "array.h"
#include <stdlib.h>

typedef void *Object;
typedef Object (*MapperVoid)(Object);
typedef Bool (*PredicateVoid)(Object);
typedef Object (*ReducerVoid)(Object, Object);
typedef void (*Displayer)(Object);
typedef struct
{
  Object *array;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;

ArrayVoid_ptr init_void_array(Object array, int length, int size);
void display(ArrayVoid_ptr array, Displayer displayer);

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper);
ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate);
Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer);

#endif