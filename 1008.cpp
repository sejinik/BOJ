#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << setprecision(9);
	cout << fixed;

	double a, b;
	cin >> a >> b;
	cout << a / b << endl;

	return 0;
}