#include "../src/parser.h"
#include <check.h>
#include <stdio.h>

START_TEST(test_factor_integer) {
  char input[] = "1234";
  FILE *buffer = fmemopen(input, strlen(input), "r");
  init_lexer(buffer);

  ck_assert_uint_eq(factor(), 1234);
  fclose(buffer);
}
END_TEST

Suite *parser_suite(void) {
  Suite *suite;
  TCase *tc_factor;

  suite = suite_create("Parser");
  tc_factor = tcase_create("factor");

  tcase_add_test(tc_factor, test_factor_integer);

  suite_add_tcase(suite, tc_factor);

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
