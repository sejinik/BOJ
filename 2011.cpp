#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000

int d[5010];

int main() {
	string str;
	cin >> str;
	int size = str.size();

	str = " " + str;

	d[0] = 1;
	for (int i = 1; i <= size; i++) {
		int x = str[i] - '0';
		if (1 <= x && x <= 9) {
			d[i] += d[i - 1];
			d[i] %= MOD;
		}

		if (i == 1) continue;
		if (str[i - 1] == '0') continue;

		x = (str[i - 1] - '0') * 10 + (str[i] - '0');
		if (10 <= x && x <= 26) {
			d[i] += d[i - 2];
			d[i] %= MOD;
		}
	}
	printf("%d\n", d[size]);
	return 0;
}