#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll f[101], g[101], h[101];
int t;

int main() {
	scanf(" %d", &t);
	f[0] = 1;
	f[1] = 1;
	g[0] = 0;
	g[1] = 1;
	h[0] = 0;
	h[1] = 1;
	for (int i = 2; i <= 100; i++) {
		f[i] = f[i - 1] + f[i - 2] + h[i - 1] * 2 + g[i - 1];
		g[i] = f[i - 1] + g[i - 2];
		h[i] = f[i - 1] + h[i - 1];
		if (f[i] >= 4200000000LL) break;
	}
	while (t--) {
		int x; scanf(" %d", &x);
		printf("%lld\n", f[x]);
	}
}