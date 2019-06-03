#include "../src/sqd3_types.h"
#include <check.h>
#include <stdio.h>

START_TEST(test_init_integer) {
  integer *value = malloc(sizeof(integer));
  *value = 1000;

  SQD3_OBJECT *object = integer_from_long_long(*value);

  free(value);

  ck_assert_int_eq(read_integer_from_object(object), 1000);
  ck_assert_int_eq(object->object_type, T_INTEGER);

  free_object(object);
}
END_TEST

Suite *parser_suite(void) {
  Suite *suite;
  TCase *tc_integer;

  tc_integer = tcase_create("integers");

  suite = suite_create("SQD3 Types");

  tcase_add_test(tc_integer, test_init_integer);

  suite_add_tcase(suite, tc_integer);

  return suite;
}

int main() {
  int number_failed;
  Suite *suite;
  SRunner *suite_runner;

  suite = parser_suite();
  suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return number_failed;
}
