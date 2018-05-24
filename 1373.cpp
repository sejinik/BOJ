#include <iostream>
#include <string>
using namespace std;
string s;
int main() {
	cin >> s;
	int n = s.size();
	n %= 3;
	if(n!= 0) n = 3 - n;
	while (n--) s = '0' + s;
	n = s.size();
	for (int i = 0; i < n - 2; i += 3) {
		int a = 0;
		if (s[i] == '1') a += 4;
		if (s[i + 1] == '1') a += 2;
		if (s[i + 2] == '1') a += 1;
		printf("%d", a);
	}
	puts("");
}