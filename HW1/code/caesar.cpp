#include <iostream>
#include <string>
using namespace std;

int main () {
    string cipher_text = "FBUQIUUDSHOFJOEKHDQCUMYJXJXUIQCUAUOQDTKFBEQTJEBUQHDYDWYDPZK";
    int offset;

    for ( offset = 1; offset <= 25; ++offset ) {
        string temp_string = cipher_text;
        for ( auto & chr : temp_string ) {
            if ( chr + offset <= 'Z' ) {
                chr += offset;
            } else {
                chr = chr + offset - 26;
            }
        }

        cout << " Possible plain text with offset = " << offset
             << " : " << temp_string << endl;
    }
}