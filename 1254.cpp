#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;

bool isPail(int a, int b) {
	if (a == b) return true;
	if (a + 1 == b) {
		if (s[a] == s[b]) return true;
		return false;
	}
	if (s[a] == s[b]) return isPail(a + 1, b - 1);
	return false;
}

int main() {
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (isPail(i, n - 1)) {
			printf("%d\n", n + i); return 0;
		}
	}
}