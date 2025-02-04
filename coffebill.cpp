#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	string name;
	cout << "Customer's first name: "; // input name
	getline(cin, name);

	int cupCount;
	cout << "number of cups: "; // input number of cups
	cin >> cupCount;

	if (cin.fail()) { // prevents error when a non-numeric value is entered
		cin.clear();
		cin.ignore();
	}

	string type;
	cout << "Type of coffee (r=regular, d=decaf): "; // input type
	cin >> type;

	string extras;
	cout << "Any extra items? (y/n): "; // input extra items
	cin >> extras;

	string day;
	cout << "Day of the week: "; // enter weekday
	cin >> day;

	if (name != "" && name[0] > 64 && name[0] < 91) { // validate name
		if (cupCount > 0) { // validate number of cups
			if (type == "r" || type == "d") { // validate type
				if (extras == "y" || extras == "n") { // validate extra
					double total;
					if (type == "r") { // regular
						total = cupCount * 4;
					} else { // decaf
						total = cupCount * 4.5;
					}
					if (extras == "y") {
						total += 1.95;
					}
					cout << fixed << setprecision(2); // set digits to 2
					if (day == "Monday" || day == "Tuesday" || day == "Thursday" || day == "Friday" || day == "Saturday" || day == "Sunday") {
						cout << "---" << endl;
						cout << "The total charge for " << name << " is $" << total << endl;
					} else if (day == "Wednesday") {
						cout << "---" << endl;
						cout << "The total charge for " << name << " is $" << total*0.85 << endl;
					} else {
						cout << "---" << endl;
						cout << "You must enter a valid day of the week.";
					}
				} else {
					cout << "---" << endl;
					cout << "You must enter y or n.";
				}
			} else {
				cout << "---" << endl;
				cout << "You must enter r or d. ";
			}
		} else {
			cout << "---" << endl;
			cout << "The number of cups must be positive.";
		}
	} else {
		cout << "---" << endl;
		cout << "The first name must start with an uppercase letter.";
	}

}