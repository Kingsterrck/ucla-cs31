// Code for Project 1
// Report poll results

#include <iostream>
using namespace std;

int main()
{
    int numberSurveyed;
    int forHarris;
    int forTrump;

    cout << "How many registered voters were surveyed? ";
    cin >> numberSurveyed;
    cout << "How many of them say they will probably vote for Harris? ";
    cin >> forHarris;
    cout << "How many of them say they will probably vote for Yump? ";
    cin >> forTrump;

    double pctHarris = 100.0 * forHarris / numberSurveyed;
    double pctTrump = 100.0 * forTrump / numberSurveyed;

    cout.setf(ios::fixed);
    cout.precision(1);

    cout << endl;
    cout << pctHarris << "% say they will probably vote for Harris." << endl;
    cout << pctTrump << "% say they will probably vote for Trump." << endl;

    if (forHarris < forTrump) // incorrect comparison is introduced
        cout << "Harris is predicted to win the election." << endl;
    else
        cout << "Trump is predicted to win the election." << endl;
}