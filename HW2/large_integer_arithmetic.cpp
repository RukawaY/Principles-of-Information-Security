#include "large_integer_arithmetic.h"

string large_int_add(const string& num1, const string& num2, int len1, int len2) {
    int ptr1 = len1 - 1;
    int ptr2 = len2 - 1;
    int carry = 0;
    int temp;
    string result = "";

    if (num1[0] == '-' && num2[0] == '-') {
        return "-" + large_int_add(num1.substr(1), num2.substr(1), len1 - 1, len2 - 1);
    } else if (num1[0] == '-') {
        return large_int_sub(num2, num1.substr(1), len2, len1 - 1);
    } else if (num2[0] == '-') {
        return large_int_sub(num1, num2.substr(1), len1, len2 - 1);
    }

    while (ptr1 >= 0 && ptr2 >= 0) {
        temp = num1[ptr1]-'0' + num2[ptr2]-'0' + carry;
        if (temp >= 10) {
            temp -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result = to_string(temp) + result;

        ptr1--;
        ptr2--;
    }

    while (ptr1 >= 0) {
        temp = num1[ptr1]-'0' + carry;
        if (temp >= 10) {
            temp -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result = to_string(temp) + result;

        ptr1--;
    }

    while (ptr2 >= 0) {
        temp = num2[ptr2]-'0' + carry;
        if (temp >= 10) {
            temp -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result = to_string(temp) + result;

        ptr2--;
    }

    if (carry != 0) {
        result = to_string(carry) + result;
    }

    return result;
}

string large_int_sub(const string& num1, const string& num2, int len1, int len2) {
    int ptr1 = len1 - 1;
    int ptr2 = len2 - 1;
    int borrow = 0;
    int temp;
    string result = "";

    if (num1[0] == '-' && num2[0] != '-') {
        return "-" + large_int_add(num1.substr(1), num2, len1 - 1, len2);
    } else if (num1[0] != '-' && num2[0] == '-') {
        return large_int_add(num1, num2.substr(1), len1, len2 - 1);
    } else if (num1[0] == '-' && num2[0] == '-') {
        return "-" + large_int_sub(num1.substr(1), num2.substr(1), len1 - 1, len2 - 1);
    }

    if (compare_int(num1, num2, len1, len2) == -1) {
        result = "-" + large_int_sub(num2, num1, len2, len1);
        return result;
    } else if (compare_int(num1, num2, len1, len2) == 0) {
        return "0";
    }

    while (ptr2 >= 0) {
        int temp1 = num1[ptr1] - '0';
        int temp2 = num2[ptr2] - '0';
        if (temp1 - borrow - temp2 < 0) {
            temp = temp1 + 10 - temp2 - borrow;
            borrow = 1;          
        } else {
            temp = temp1 - temp2 - borrow;
            borrow = 0;
        }

        result = to_string(temp) + result;

        ptr1--;
        ptr2--;
    }

    while (ptr1 >= 0) {
        int temp1 = num1[ptr1] - '0';
        
        if (temp1 - borrow >= 0) {
            temp = temp1 - borrow;
            borrow = 0;
        } else {
            temp = temp1 + 10 - borrow;
            borrow = 1;
        }

        result = to_string(temp) + result;

        ptr1--;
    }

    remove_redundant_zero(result);

    return result;
}

string large_int_mul(const string& num1, const string& num2, int len1, int len2) {
    string result = "";
    int ptr = len2 - 1;
    int count = 0;
    int temp, len_product;
    string product;

    if (num1[0] == '-' && num2[0] != '-') {
        return "-" + large_int_mul(num1.substr(1), num2, len1 - 1, len2);
    } else if (num1[0] != '-' && num2[0] == '-') {
        return "-" + large_int_mul(num1, num2.substr(1), len1, len2 - 1);
    } else if (num1[0] == '-' && num2[0] == '-') {
        return large_int_mul(num1.substr(1), num2.substr(1), len1 - 1, len2 - 1);
    }

    while (ptr >= 0) {
        temp = num2[ptr] - '0';

        product = large_int_mul_single(num1, temp, len1);
        len_product = product.length();

        for (int i = 0; i < count ; ++i) {
            product += "0";
            len_product++;
        }

        result = large_int_add(result, product, result.length(), len_product);

        ptr--;
        count++;
    }

    remove_redundant_zero(result);

    return result;
}

string large_int_div(const string& num1, const string& num2, int len1, int len2) {
    string result = "";
    string dividend = num1;
    string current;
    int ptr = 0;
    int count = 0;
    int num_zeros_to_add = len1 - 1;
    int try_quotient;

    if (num2 == "0") {
        return "0 Divisor!";
    }

    if (num1[0] == '-' && num2[0] != '-') {
        return "-" + large_int_div(num1.substr(1), num2, len1 - 1, len2);
    } else if (num1[0] != '-' && num2[0] == '-') {
        return "-" + large_int_div(num1, num2.substr(1), len1, len2 - 1);
    } else if (num1[0] == '-' && num2[0] == '-') {
        return large_int_div(num1.substr(1), num2.substr(1), len1 - 1, len2 - 1);
    }

    while (count <= len1 - 1) {
        // get current dividend
        current = dividend.substr(0, ptr + 1);

        if (compare_int(current, num2, current.length(), len2) < 0) {
            // if dividend < dividor, add 0 and continue
            if(result != "") {
                result.append("0");
            }           
        } else {
            // get correct quotient digit and temp product
            int original_digits = dividend.length();

            try_quotient = 1;
            string temp_product = large_int_mul_single(num2, try_quotient, len2);
            while (compare_int(temp_product, current, temp_product.length(), current.length()) <= 0) {
                try_quotient++;
                temp_product = large_int_mul_single(num2, try_quotient, len2);
            }
            try_quotient--;
            temp_product = large_int_mul_single(num2, try_quotient, len2);

            result.append(to_string(try_quotient));

            // add zeros to temp product
            for (int i = 0; i < num_zeros_to_add ; ++i) {
                temp_product.append("0");
            }

            // subtract product from dividend
            dividend = large_int_sub(dividend, temp_product, dividend.length(), temp_product.length());

            int new_digits = dividend.length();

            // update non_zero_ptr
            ptr = ptr - original_digits + new_digits;
        }

        ptr++;
        num_zeros_to_add--;
        count++;
    }

    if (result == "") {
        result = "0";
    }

    return result;
}

string large_int_mod(const string& num1, const string& num2, int len1, int len2) {
    string quotient = large_int_div(num1, num2, len1, len2);
    string product = large_int_mul(quotient, num2, quotient.length(), len2);
    string result = large_int_sub(num1, product, len1, product.length());

    return result;
}

int compare_int(const string &num1, const string &num2, int len1, int len2) {
    if (num1[0] == '-' && num2[0] != '-') {
        return -1;
    } else if (num1[0] != '-' && num2[0] == '-') {
        return 1;
    } else if (num1[0] == '-' && num2[0] == '-') {
        return -compare_int(num2.substr(1), num1.substr(1), len2 - 1, len1 - 1);
    }
    
    if (len1 > len2) {
        return 1;
    } else if (len1 < len2) {
        return -1;
    } else {
        if (num1 == num2) {
            return 0;
        } else if (num1 > num2) {
            return 1;
        } else {
            return -1;
        }
    }
}

string large_int_mul_single(const string& num1, const int& num2, int len1) {
    int ptr = len1 - 1;
    int carry = 0;
    int temp;
    string result = "";

    while (ptr >= 0) {
        temp = num1[ptr] - '0';
        temp = temp * num2 + carry;

        carry = temp / 10;
        temp = temp % 10;

        result = to_string(temp) + result;

        ptr--;
    }

    if (carry != 0) {
        result = to_string(carry) + result;
    }

    return result;
}

void remove_redundant_zero(string &str) {
    int ptr = 0;
    int len = str.length();

    while (str[ptr] == '0' && ptr < len - 1) {
        ptr++;
    }

    str = str.substr(ptr);
}