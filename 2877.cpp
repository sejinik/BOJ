#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	int a = 1;
	while (n >= a) {
		n -= a; a *= 2;
	}
	string str = "";
	while (a/=2) str += '4';
	for (int i = 0; (1 << i) <= n; i++) {
		if ((1 << i)&n) str[i] = '7';
	}
	reverse(str.begin(), str.end());
	cout << str << endl;
}