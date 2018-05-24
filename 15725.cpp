#include <iostream>
#include <string>
using namespace std;
string a, b;
int x, y, xcnt;
int main() {
	string str; cin >> str;
	for (int i = 0; str[i]; i++) {
		if (str[i] != 'x') {
			if (!xcnt) a += str[i];
			else b += str[i];
		}
		else {
			if (!xcnt) {
				if (a == "") x = 1;
				else if (a == "-") x = -1;
				else x = stoi(a);
			}
			else {
				if (b == "+") y = 1;
				else if (b == "-") y = -1;
				else y = stoi(b);
			}
			xcnt += 1;
		}
	}
	printf("%d\n", x + y);
}