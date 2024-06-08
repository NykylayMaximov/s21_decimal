#include "../s21_decimal.h"

int main() {
    s21_decimal a = {{-1, -1, -1, -2147483648}};            // -79228162514264337593543950335
    s21_decimal b = {{6, 0, 0, -2147418112}};  // -0.6
    s21_decimal res_bits = {{0, 0, 0, 0}};
    s21_decimal check = {{-1717986919, -1717986919, -1717986919, 0}};

    
    int res = s21_mul(a, b, &res_bits);

    print_decimal_bin(a);
    print_decimal_bin(b);
    print_decimal_bin(res_bits);
    print_decimal_bin(check);
    printf("ERROR - %d\n", res);

    return 0;
}