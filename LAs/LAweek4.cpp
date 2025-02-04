#include <iostream>
using namespace std;

int main() {
    // int n;
    // cin >> n;
    // int count = 0;
    // while (n != 0) {
    //     int temp = n % 10;
    //     count *= 10;
    //     count += temp;
    //     n /= 10;
    // }
    // cout << count;

    string n;
    cin >> n;
    string s;
    for (int i = 0; i < n.length(); i++) {
        if (isupper(n[i])) {
            s += tolower(n[i]);
        } else {
            s += n[i];
        }
    }
    cout << s << endl;
}