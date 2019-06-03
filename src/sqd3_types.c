#include "sqd3_types.h"

SQD3_OBJECT *integer_from_long_long(integer value) {
  SQD3_OBJECT *ref = malloc(sizeof(integer) + sizeof(object_t));

  ref->object_type = T_INTEGER;
  ref->value = (void *)&value;

  return ref;
}

integer read_integer_from_object(SQD3_OBJECT *object) {
  return *((integer *)object->value);
}

void free_object(SQD3_OBJECT *object) { free(object); }
