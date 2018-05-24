#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a, b,c;

	cin >> a >> b >> c;

	if (b == "*") {
		cout << a;
		for (int i = 1; i < c.size(); i++) {
			cout << c[i];
		}
	}

	else {
		if (a != c) {
			string big, small;
			big = max(a, c);
			small = min(a, c);

			for (int i = 0; i < big.size() - small.size(); i++) {
				cout << big[i];
			}
			cout << small;
		}
		else {
			cout << 2;
			for (int i = 1; i < a.size(); i++)
				cout << a[i];
		}
	}

	cout << endl;
	return 0;
}