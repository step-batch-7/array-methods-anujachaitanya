#include "../array.h"
#include "assert.h"
#include <stdio.h>

int increment(number)
{
  return ++number;
}
void test_map_for_empty_array(void)
{
  char description[] = "Should map empty array";
  int a[0];
  Array_ptr expected = init_array(a, 0);
  Array_ptr actual = map(expected, increment);
  Bool result = assert_array(actual, expected);
  show_result(result, description);
}

int main(void)
{
  test_map_for_empty_array();
  return 0;
}