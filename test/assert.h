#include "../array.h"
#ifndef __ASSRET_H
#define __ASSERT_H

typedef enum
{
  False,
  True
} Bool;

Bool assert_array(Array_ptr actual, Array_ptr expected);

#endif