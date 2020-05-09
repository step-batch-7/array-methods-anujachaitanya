#include "assert.h"
#include <stdio.h>
void show_result(Bool result, char *description)
{
  if (result)
  {
    printf("%s", PASS);
  }
  else
  {
    printf("%s", FAILED);
  }
  printf("%s\n", description);
}

Bool assert_array(Array_ptr actual, Array_ptr expected)
{
  Bool result = True;
  if (actual->length != expected->length)
  {
    return False;
  }
  int counter = 0;
  while (counter < actual->length)
  {
    if (actual->array[counter] != expected->array[counter])
    {
      result = False;
      break;
    }
  }
  return result;
}