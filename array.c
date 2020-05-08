#include <stdlib.h>
#include <stdio.h>
#include "array.h"

Array *map(Array *array, Mapper mapper)
{
  int result[array->length];
  for (size_t i = 0; i < array->length; i++)
  {
    int map_result = (*mapper)(array->array[i]);
    result[i] = map_result;
  }
  Array *result_array = init_array(result, array->length);
  return result_array;
}

Array *filter(Array *array, Predicate predicate)
{
  int result[array->length];
  int result_length = 0;
  for (size_t i = 0; i < array->length; i++)
  {
    Bool filter_result = (*predicate)(array->array[i]);
    if (filter_result)
    {
      result[result_length] = array->array[i];
      result_length++;
    }
  }
  Array *result_array = init_array(result, result_length);
  return result_array;
}

Array *init_array(Int_ptr array, int length)
{
  Array *new_array = malloc(sizeof(Array));
  new_array->array = malloc(sizeof(int) * length);
  new_array->length = length;
  int count = 0;
  while (count < length)
  {
    new_array->array[count] = array[count];
    count++;
  }
  return new_array;
}

int reduce(Array *array, int context, Reducer reducer)
{
  for (size_t i = 0; i < array->length; i++)
  {
    context = (*reducer)(context, array->array[i]);
  }
  return context;
}

void display_result(Array *result)
{
  int counter = 0;
  while (counter < result->length)
  {
    printf("%d\t", result->array[counter]);
    counter++;
  }
  printf("\n");
}