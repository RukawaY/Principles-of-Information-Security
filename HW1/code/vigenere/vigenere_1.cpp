#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string cipher_text = "ktbueluegvitnthuexmonveggmrcgxptlyhhjaogchoemqchpdnetxupbqntietiabpsmaoncnwvoutiugtagmmqsxtvxaoniiogtagmbpsmtuvvihpstpdvcrxhokvhxotawswquunewcgxptlcrxtevtubvewcnwwsxfsnptswtagakvoyyak";

    vector<int> key_lengths = {2, 3, 4, 5, 6, 7, 8};

    for(auto key_len : key_lengths) {
        vector<string> texts(key_len, "");
        vector<double> prob = {};

        for (int i = 0; i < cipher_text.length(); i++) {
            texts[i % key_len] += cipher_text[i];
        }

        for (auto text : texts) {
            vector<int> frequency(26, 0);

            for (auto chr : text) {
                frequency[chr - 'a']++;
            }

            double probability = 0;

            for (auto freq : frequency) {
                probability += freq * (freq - 1);
            }

            int n = text.length();
            probability = probability / (n * (n - 1));
            prob.push_back(probability);
        }

        cout << "Testing with key length = " << key_len << ": p = ";
        double average = 0;
        for(auto p : prob) {
            cout << p << " ";
            average += p;
        }

        cout << ", with average = " << average / key_len << endl;
    }
}