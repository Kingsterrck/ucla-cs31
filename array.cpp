#include <iostream>
#include <cassert>
using namespace std;

int locateMaximum(const string array[], int n) {
	int count = 0;
    if (n <= 0) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        if (array[i] > array[count]) {
            count = i;
        }
    }
    return count;
}

int countFloatingPointValues(const string array[ ], int n ) {
    if (n <= 0) {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (empty(array[i])) {
            continue;
        }
        bool isFloat = true;
        bool decimalCheck = false;
        for (char c:array[i]) {
            if (!isdigit(c)) {
                if (c == '.' && !decimalCheck) {
                    decimalCheck = true;
                } else {
                    isFloat = false;
                    break;
                }
            }
        }
        if (isFloat) {
            count++;
        }
    }
    return count;
}

bool hasNoCapitals(const string array[ ], int n) {
    if (n <= 0) {
        return true;
    }
    for (int i = 0; i < n; i++) {
        for (char c:array[i]) {
            if (c >= 65 && c <= 90) {
                return false;
            }
        }
    }
    return true;
}
int shiftLeft(string array[], int n, int amount, string placeholder) {
    if (n <= 0 || amount < 0) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        if (i - amount >= 0) {
            array[i-amount] = array[i];
        }
    }
    int count = 0;
    for (int i = n-1; i > n-1-amount; i--) {
        array[i] = placeholder;
        count++;
        if (i == 0) {
            break;
        }
    }
    return count;
}

int main() {

}
