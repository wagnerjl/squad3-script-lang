#ifndef __SQD3_TYPES_H__
#define __SQD3_TYPES_H__

#include <stdlib.h>

typedef long long integer;

typedef enum {
  T_INTEGER,
} object_t;

typedef struct SQD3_OBJECT {
  object_t object_type;
  void *value;
} SQD3_OBJECT;

SQD3_OBJECT *integer_from_long_long(integer value);
integer read_integer_from_object(SQD3_OBJECT *object);

void free_object(SQD3_OBJECT *object);

#endif
