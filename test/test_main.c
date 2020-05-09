#include "../array.h"
#include "assert.h"
#include <stdio.h>

int increment(number)
{
  return ++number;
}

int square(number)
{
  return number * number;
}

int add(int initial, int number)
{
  return initial + number;
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

void test_map_for_any_mapper(void)
{
  char description[] = "Should map elements for taking square for each element";
  int expected_values[] = {1, 4, 9, 16};
  Array_ptr expected = init_array(expected_values, 4);
  int input_values[] = {1, 2, 3, 4};
  Array_ptr input = init_array(input_values, 4);
  Array_ptr actual = map(input, square);
  Bool result = assert_array(actual, expected);
  show_result(result, description);
}

void test_reduce_for_empty_array(void)
{
  char description[] = "Should return init as it is for empty list for reduce";
  int input_values[0];
  Array_ptr actual = init_array(input_values, 0);
  int reduce_result = reduce(actual, 10, add);
  Bool result = assert_int(reduce_result, 10);
  show_result(result, description);
}

void test_reduce_for_addition(void)
{
  char description[] = "Should return the value for list for add function for reduce";
  int input_values[5] = {1, 2, 3, 4, 5};
  Array_ptr actual = init_array(input_values, 5);
  int reduce_result = reduce(actual, 0, add);
  Bool result = assert_int(reduce_result, 15);
  show_result(result, description);
}

int main(void)
{
  test_map_for_empty_array();
  test_map_for_any_mapper();
  test_reduce_for_empty_array();
  test_reduce_for_addition();
  return 0;
}