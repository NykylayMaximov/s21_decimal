#include "../s21_decimal.h"


int main() {
  s21_decimal a = {{-1, 0, 0, 0x1C8000}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};


  s21_decimal result;
  int code = s21_div(a, b, &result);

  float num;
  
  s21_from_decimal_to_float(result, &num);

    print_decimal_bin(a);
    print_decimal_bin(b);
    print_decimal_bin(result);
    //print_decimal_bin(check);
    printf("%e\n", num);
    printf("ERROR - %d\n", code);
    printf("scale 1 - %d    scale 2 - %d    scale res - %d\n", get_scale(a), get_scale(b), get_scale(result));

    return 0;
}

/*/
int main() {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int value_type_result = 0;
  float a = 5224, b = 235;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float rez = 0, origin_rez = a / b;
  value_type_result = s21_div(src1, src2, &result);
  //value_type_origin = 0;
  s21_from_decimal_to_float(result, &rez);
    

    print_decimal_bin(src1);
    print_decimal_bin(src2);
    print_decimal_bin(result);

    //print_decimal_bin(return_value);

    //printf("%f\n", result_float);
    //print_decimal_bin(check);
    printf("%e\n", rez);
    printf("%e\n", origin_rez);
    printf("ERROR - %d\n", value_type_result);
    printf("scale 1 - %d    scale 2 - %d    scale res - %d\n", get_scale(src1), get_scale(src2), get_scale(result));

    return 0;
}/*/
/*/
int main() {
  float a = -23748280, b = 0;
  s21_decimal number = {0};
  s21_from_float_to_decimal(a, &number);
  s21_from_decimal_to_float(number, &b);
  print_decimal_bin(number);
  printf("%f  %f\n", a, b);
  printf("%e  %e\n", a, b);
  return 0;
}/*/