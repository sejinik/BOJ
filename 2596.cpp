#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int ch[8] = { 0,15,19,28,38,41,53,58 };
int n;
string s, p;

int go(int x) {
	for (int i = 0; i < 8; i++) {
		int c = x^ch[i];
		if (c == 0 || c == 1 || c == 2 || c == 4 || c == 8 || c == 16 || c == 32) return i;
	}
	return -1;
}
int main() {
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < n; i++) {
		int c = 1;
		int cnt = 0;
		for (int j = i*6+5; j >= i*6; j--) {
			if (s[j] == '1') cnt += c;
			c *= 2;
		}
		if (go(cnt) == -1) {
			printf("%d\n", i + 1); return 0;
		}
		else p += go(cnt) + 'A';
	}
	cout << p << endl;
}