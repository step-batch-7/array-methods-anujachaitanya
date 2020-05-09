#include "array_void.h"
#include <stdio.h>

ArrayVoid_ptr init_void_array(Object array, int length, int size)
{
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->array = malloc(sizeof(Object) * length);
  new_array->length = 0;

  while (new_array->length < length)
  {
    new_array->array[new_array->length] = array + (new_array->length * size);
    new_array->length++;
  }
  return new_array;
};

void display(ArrayVoid_ptr array, Displayer displayer)
{
  int counter = 0;
  while (counter < array->length)
  {
    (*displayer)(array->array[counter]);
    counter++;
  }
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr result = malloc(sizeof(ArrayVoid));
  result->array = malloc(src->length * sizeof(Object));
  result->length = src->length;
  for (int indx = 0; indx < src->length; indx++)
  {
    result->array[indx] = (*mapper)(src->array[indx]);
  }
  return result;
};

ArrayVoid_ptr resize_array(ArrayVoid_ptr previous_array)
{
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->array = malloc(sizeof(Object) * previous_array->length);
  new_array->length = 0;
  while (new_array->length < previous_array->length)
  {
    new_array->array[new_array->length] = previous_array->array[new_array->length];
    new_array->length++;
  }
  return new_array;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  ArrayVoid_ptr result = malloc(sizeof(ArrayVoid));
  result->array = malloc(src->length * sizeof(Object));
  result->length = 0;
  int counter = 0;
  while (counter < src->length)
  {
    Bool filter_result = (*predicate)(src->array[counter]);
    if (filter_result)
    {
      result->array[result->length] = src->array[counter];
      result->length++;
    }
    counter++;
  }
  return resize_array(result);
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  for (size_t i = 0; i < src->length; i++)
  {
    init = (*reducer)(init, src->array[i]);
  }
  return init;
}