#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// int n;
	//    cin >> n;
	//    int count = 0;
	//    while (n != 0) {
	//        int temp = n % 10;
	//        count += temp;
	//        n /= 10;
	//    }
	//    cout << count << endl;

	// int n;
	// cin >> n;
	// int arr[n];
	// int count = 0;
	// for (int i = 1; i <= n-1; i++) {
	// 	if (n % i == 0) {
	// 		arr[count] = i;
	// 		count++;
	// 	}
	// }
	// int total = 0;
	// for (int i = 0; i < count; i++) {
	// 	total += arr[i];
	// }
	// if (total == n) {
	// 	cout << "YES";
	// } else {
	// 	cout << "NO";
	// }

	int n;
	cin >> n;
	int count = 1;
	bool found = false;
	while (!found) {
		if (n < pow(2,count)) {
			cout << count-1 << endl;
			found = true;
		} else {
			count++;
		}
	}
	return 0;
}