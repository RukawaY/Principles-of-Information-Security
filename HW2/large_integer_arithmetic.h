#ifndef _LARGE_INTEGER_ARITHMETIC_H
#define _LARGE_INTEGER_ARITHMETIC_H

#include <string>
using namespace std;

string large_int_add(const string &num1, const string &num2, int len1, int len2);
string large_int_sub(const string &num1, const string &num2, int len1, int len2);
string large_int_mul(const string &num1, const string &num2, int len1, int len2);
string large_int_div(const string &num1, const string &num2, int len1, int len2);
string large_int_mod(const string &num1, const string &num2, int len1, int len2);
int compare_int(const string &num1, const string &num2, int len1, int len2);
string large_int_mul_single(const string& num1, const int& num2, int len1);
void remove_redundant_zero(string &str);

#endif