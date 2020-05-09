#include "../array.h"
#include "assert.h"
#include <stdio.h>

int increment(number)
{
  return ++number;
}
void test_map_for_empty_array(void)
{

  int a[0];
  Array_ptr expected = init_array(a, 0);
  Array_ptr actual = map(expected, increment);
  Bool result = assert_array(actual, expected);
  printf("%d", result);
}