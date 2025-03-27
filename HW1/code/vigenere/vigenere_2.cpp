#include <iostream>
#include <vector>
#include <string>
using namespace std;

double calculate_MIC(vector<string>& C, int i, int j, int k);

int main() {
    string cipher_text = "ktbueluegvitnthuexmonveggmrcgxptlyhhjaogchoemqchpdnetxupbqntietiabpsmaoncnwvoutiugtagmmqsxtvxaoniiogtagmbpsmtuvvihpstpdvcrxhokvhxotawswquunewcgxptlcrxtevtubvewcnwwsxfsnptswtagakvoyyak";
    vector<string> C(3, "");

    for (int i = 0; i < cipher_text.length(); i++) {
        C[i % 3] += cipher_text[i];
    }

    vector<vector<vector<double>>> MIC(3, vector<vector<double>>(3, vector<double>(26, 0)));

    double max_MIC;
    int max_k;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i >= j)
                continue;

            max_MIC = 0;
            max_k = 0;

            for (int k = 0; k < 26; k++) {
                MIC[i][j][k] = calculate_MIC(C, i, j, k);
                if (MIC[i][j][k] > max_MIC) {
                    max_MIC = MIC[i][j][k];
                    max_k = k;
                }
            }

            cout << "MIC(" << i << "," << j << ") = " << max_MIC << " (offset = " << max_k << ")" << endl;
        }
    }
}

double calculate_MIC(vector<string>& C, int i, int j, int k) {
    double MIC = 0;
    
    string Si = C[i];
    string Sj = C[j];
    
    vector<double> freq_i(26, 0), freq_j(26, 0);

    for (int l = 0; l < Si.length(); l++) {
        freq_i[Si[l] - 'a']++;
    }

    for (int l = 0; l < Sj.length(); l++) {
        freq_j[Sj[l] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        freq_i[i] = freq_i[i] * 1.0 / Si.length();
        freq_j[i] = freq_j[i] * 1.0 / Sj.length();
    }

    for(int l = 0; l < 26; l++) {
        int index = (l + k) % 26;
        MIC += freq_i[l] * freq_j[index];
    }

    return MIC;
}