#include <iostream>
using namespace std;

int main() {
    // int a, b, c;
    // cin >> a;
    // cin >> b;
    // cin >> c;
    // if (a > b) {
    //     if (c > a) {
    //         cout << c << endl;
    //     } else {
    //         cout << a << endl;
    //     }
    // } else {
    //     if (c > b) {
    //         cout << c << endl;
    //     } else {
    //         cout << b << endl;
    //     }
    // }

    string s;
    getline(cin, s);
    string temp;
    string temp2;
    string result;
    while (!s.empty()) {
        if (s[0] != ' ') {
            temp += s[0];
            s = s.substr(1, s.size()-1);
        } else {
            for (int i = temp.size()-1; i >= 0; i--) {
                temp2 += temp[i];
            }
            result += temp2 + " ";
            temp = "";
            temp2 = "";
            s = s.substr(1, s.size()-1);
        }
    }
    for (int i = temp.size()-1; i >= 0; i--) {
        temp2 += temp[i];
    }
    result += temp2;
    temp = "";
    temp2 = "";

    cout << result << endl;
}