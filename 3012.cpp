#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define ll long long
ll mod = 100000;
int n;
string str;
ll d[222][222];
char open[5] = "({[";
char close[5] = ")}]";
bool check;
ll go(int i, int j) {
	if (i > j) return 1;
	ll&ret = d[i][j];
	if (ret != -1) return ret;
	ret = 0;

	for (int k = i + 1; k <= j; k += 2) {
		for (int l = 0; l < 3; l++) {
			if (str[i] == open[l] || str[i] == '?') {
				if (str[k] == close[l] || str[k] == '?') {
					ll temp = go(i + 1, k - 1)*go(k + 1, j);
					if (ret +temp> mod) check = true;
					ret += temp;
					ret %= mod;
				}
			}
		}
	}
	return ret;
}

int main() {
	memset(d, -1, sizeof(d));
	scanf(" %d", &n);
	cin >> str;
	if (n & 1) {
		puts("0"); return 0;
	}
	ll ans = go(0, n - 1);
	if (check) {
		printf("%05lld\n", ans);
	}
	else printf("%lld\n", ans);
}