#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool check[2525][2525];
int d[2525];

int main() {
	memset(d, -1, sizeof(d));
	string str;
	cin >> str;
	int n = str.size();
	str = " " + str;

	for (int i = 1; i <= n; i++)
		check[i][i] = true;

	for (int i = 1; i < n; i++)
		if (str[i] == str[i + 1])
			check[i][i + 1] = true;

	for (int k = 2; k < n; k++) {
		for (int i = 1; i <= n-k; i++) {
			int j = i + k;
			if (str[i] == str[j] && check[i + 1][j - 1]) {
				check[i][j] = true;
			}
		}
	}

	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (check[j][i]) {
				if (d[i] == -1 || d[i] > d[j - 1] + 1) {
					d[i] = d[j - 1] + 1;
				}
			}
		}
	}
	printf("%d\n", d[n]);
	return 0;
}