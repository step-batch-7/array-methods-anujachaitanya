#include "../array.h"

#ifndef __ASSRET_H
#define __ASSERT_H

#define PASS "✅"
#define FAILED "❌"

void show_result(Bool result, char *description);

Bool assert_int(int actual, int expected);
Bool assert_array(Array_ptr actual, Array_ptr expected);

#endif