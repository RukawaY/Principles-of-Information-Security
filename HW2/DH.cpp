#include <iostream>
#include "large_integer_arithmetic.h"

// calculate (base ^ exp) % mod
string mod_pow(string base, string exp, string mod) {
    string result = "1";
    while (compare_int(exp, "0", exp.length(), 1) > 0) {
        if (large_int_mod(exp, "2", exp.length(), 1) == "1") {
            result = large_int_mul(result, base, result.length(), base.length());
            result = large_int_mod(result, mod, result.length(), mod.length());
        }

        base = large_int_mul(base, base, base.length(), base.length());
        base = large_int_mod(base, mod, base.length(), mod.length());

        exp = large_int_div(exp, "2", exp.length(), 1);
    }

    return result;
}

int main() {
    string p, g, a, b;

    cout << "Input p: ";
    cin >> p;
    cout << "Input g: ";
    cin >> g;
    cout << "Input A's private key: ";
    cin >> a;
    cout << "Input B's private key: ";
    cin >> b;

    string a_times_b = large_int_mul(a, b, a.length(), b.length());

    string A = mod_pow(g, a, p);
    string B = mod_pow(g, b, p);
    string K = mod_pow(g, a_times_b, p);

    cout << endl
         << "--------------------------------------------------" << endl
         << "|                    Results                     |" << endl
         << "--------------------------------------------------" << endl;

    cout << "A's public key  |  " << A << endl;
    cout << "B's public key  |  " << B << endl;
    cout << "Session key     |  " << K;

    return 0;
}