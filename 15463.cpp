#include <cstdio>
bool check[2020][2020];
int main() {
	int a, b, c, d;
	for (int i = 0; i < 2; i++) {
		scanf(" %d %d %d %d", &a, &b, &c, &d);
		a += 1000; b += 1000; c += 1000; d += 1000;
		for (int j = a; j < c; j++) {
			for (int k = b; k < d; k++) {
				check[j][k] = true;
			}
		}
	}
	scanf("%d %d %d %d", &a, &b, &c, &d);
	a += 1000; b += 1000; c += 1000; d += 1000;
	for (int i = a; i < c; i++) {
		for (int j = b; j < d; j++) {
			if (check[i][j]) check[i][j] = false;
		}
	} int ans = 0;
	for (int i = 0; i < 2002; i++) {
		for (int j = 0; j < 2002; j++) {
			if (check[i][j])ans++;
		}
	}
	printf("%d\n", ans);
}