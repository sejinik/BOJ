#include <cstdio>
int a[44], b[44];

int main() {
	a[0] = 1;
	b[1] = 1;
	a[2] = b[2] = 1;
	for (int i = 3; i <= 40; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	int t; scanf(" %d", &t);
	while (t--) {
		int x; scanf(" %d", &x);
		printf("%d %d\n", a[x], b[x]);
	}
}