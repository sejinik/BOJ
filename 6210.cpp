#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int d, n,dp;
int power[10];

int ndigits(int x) {
	int ret;
	for (ret = 0; x != 0; x /= 10, ret++);
	return ret;
}
bool prime(int x) {
	if (x <= 1) return false;
	for (int i = 2; i*i <= x; i++) if (x%i == 0) return false;
	return true;
}

bool go(int x) {
	int pos = ndigits(x);
	for (int i = 0; i < pos; i++) {
		int a = x / power[i];
		int b = x%power[i];
		if (a / dp == 0 || b / dp == 0) continue;
		if (prime(a) && prime(b)) return true;
	}
	return false;
}
int main() {
	for (int i = 0; i < 10; i++) power[i] = pow(10, i);
	scanf(" %d %d", &d, &n);
	dp = pow(10, d - 1);
	if (ndigits(n) < d) n = pow(10, d * 2 - 1);
	
	for (int i = n; i <= 2100000000; i++) {
		if (go(i)) return !printf("%d\n", i);
	}
}