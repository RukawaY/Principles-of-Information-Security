#include <iostream>
#include "large_integer_arithmetic.h"

int main() {
    string num1, num2;
    cout << "Input two large integers:" << endl
         << "Integer 1: ";
    cin >> num1;
    cout << "Integer 2: ";
    cin >> num2;

    remove_redundant_zero(num1);
    remove_redundant_zero(num2);

    int len1 = num1.length();
    int len2 = num2.length();

    string add_result = large_int_add(num1, num2, len1, len2);
    string sub_result = large_int_sub(num1, num2, len1, len2);
    string mul_result = large_int_mul(num1, num2, len1, len2);
    string div_result = large_int_div(num1, num2, len1, len2);
    string mod_result = large_int_mod(num1, num2, len1, len2);

    cout << endl
         << "--------------------------------------------------" << endl
         << "|                    Results                     |" << endl
         << "--------------------------------------------------" << endl;

    cout << "Add       |  " << add_result << endl;
    cout << "Subtract  |  " << sub_result << endl;
    cout << "Multiply  |  " << mul_result << endl;
    cout << "Divide    |  " << div_result << endl;
    cout << "Mod       |  " << mod_result;

    return 0;
}