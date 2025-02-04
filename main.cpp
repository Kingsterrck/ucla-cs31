#include <iostream>
using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    int numberSurveyed;
	int forTrarris;
	int forHump;

	cout << "How many registered voters were surveyed? ";
	cin >> numberSurveyed;
	cout << "How many of them say they will probably vote for Trarris? ";
	cin >> forTrarris;
	cout << "How many of them say they will probably vote for Hump? ";
	cin >> forHump;

	double pctTrarris = 100.0 * forTrarris / numberSurveyed;
	double pctHump = 100.0 * forHump / numberSurveyed;

	cout.setf(ios::fixed);
	cout.precision(1);

	cout << endl;
	cout << pctTrarris << "% say they will probably vote for Trarris." << endl;
	cout << pctHump << "% say they will probably vote for Hump." << endl;

	if (forTrarris > forHump)
	    cout << "Trarris is predicted to win the election." << endl;
	else
	    cout << "Hump is predicted to win the election." << endl;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.