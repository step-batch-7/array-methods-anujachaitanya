#include "array.h"
#include "array_void.h"
#include <stdio.h>

int increment(int number)
{
  return number + 1;
}

Bool is_even(int number)
{
  return number % 2 == 0;
}

int add_to(int initial_value, int number)
{
  return initial_value + number;
}

void displayer(Object number)
{
  printf("%d", *(int *)number);
}

int main(void)
{
  int a[] = {1, 2, 3, 4};
  // Array_ptr array = init_array(a, sizeof(a) / sizeof(int));

  // Array_ptr result_map = map(array, increment);
  // display_result(result_map);

  // Array_ptr result_filter = filter(array, is_even);
  // display_result(result_filter);

  // printf("%d", reduce(array, 0, add_to));
  ArrayVoid_ptr array = init_void_array(a, 4, 4);
  display(array, displayer);
  return 0;
}