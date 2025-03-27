#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string cipher_text = "ktbueluegvitnthuexmonveggmrcgxptlyhhjaogchoemqchpdnetxupbqntietiabpsmaoncnwvoutiugtagmmqsxtvxaoniiogtagmbpsmtuvvihpstpdvcrxhokvhxotawswquunewcgxptlcrxtevtubvewcnwwsxfsnptswtagakvoyyak";

    int offset_0_1 = 2, offset_1_2 = 7;
    string init_key = "ayr";
    string test_key, plain_text;

    for (int i = 0; i < 26;i++) {
        test_key = init_key;
        for (int j = 0; j < 3;j++) {
            test_key[j] = (test_key[j] - 'a' + i) % 26 + 'a';
        }

        plain_text = cipher_text;
        for (int j = 0;j<cipher_text.length();j++) {
            char c = test_key[j % 3];
            plain_text[j] = cipher_text[j] - c + 'a';
            if(plain_text[j] > 'z') {
                plain_text[j] -= 26;
            }
            if(plain_text[j] < 'a') {
                plain_text[j] += 26;
            }
        }

        cout << "Test Key: " << test_key << "  Plain Text: " << plain_text << endl;
    }
}