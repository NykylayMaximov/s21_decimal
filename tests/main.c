#include "s21_decimal_test.h"

int main(void) {
  int number_failed = 0;

  Suite *test[] = {suite_add_test(),
                   suite_sub_test(),
                   suite_mul_test(),
                   suite_div_test(),

                   suite_less_test(),
                   suite_less_or_equal_test(),
                   suite_greater_test(),
                   suite_greater_or_equal_test(),
                   suite_equal_test(),
                   suite_not_equal_test(),

                   suite_int_to_dec_test(),
                   suite_float_to_dec_test(),
                   suite_dec_to_int_test(),
                   suite_dec_to_float_test(),

                   suite_floor_test(),
                   suite_round_test(),
                   suite_truncate_test(),
                   suite_negate_test(),
                   NULL};

  for (int i = 0; test[i] != NULL; i++) {
    printf("\n\n");
    SRunner *sr = srunner_create(test[i]);

    srunner_run_all(sr, CK_VERBOSE);

    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  return 0;
  //return (number_failed == 0) ? 0 : 1;
}