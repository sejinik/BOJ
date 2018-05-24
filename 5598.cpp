#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int l = str.size();
	for (int i = 0; i < l; i++) {
		str[i] = str[i] - 3;
		if (str[i] < 'A') str[i] += 26;
	}
	cout << str << "\n";
}