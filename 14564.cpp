#include <cstdio>


int main() {
	int n, m, a;
	scanf("%d %d %d", &n, &m, &a);
	while (1) {
		int num;
		scanf("%d", &num);
		if (num == (m / 2 + 1)) {
			puts("0");
			return 0;
		}
		
		int ans = (num - (m / 2 + 1) + a + n) % n;
		if (ans == 0) ans = n;
		printf("%d\n", ans);
		a = ans;
	}
}