#include "assert.h"

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