#include <cstdio>

int tcase;

int main() {
	scanf("%d", &tcase);
	while (tcase--) {
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i < n; i++) {
			if (n%i == 0)
				sum += i;
		}
		if (sum == n) puts("Perfect");
		else if (sum > n) puts("Abundant");
		else puts("Deficient");
	}
	return 0;
}