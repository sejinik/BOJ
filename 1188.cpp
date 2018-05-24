#include <cstdio>

int gcd(int x, int y) {
	if (y != 0) gcd(y, x%y);
	else return x;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int num = gcd(n, m);
	
	n /= num;
	m /= num;
	int ans = num*(m - 1);
	printf("%d\n", ans);
	return 0;
}