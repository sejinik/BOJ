#include <cstdio>

int n, k, b;
bool check[100010];

int main() {
	scanf("%d %d %d", &n, &k, &b);
	for (int i = 0; i < b; i++) {
		int temp;
		scanf("%d", &temp);
		check[temp] = true;
	}

	int ans = 100010;
	for (int i = 1; i <= n-k+1; i++) {
		int cnt = 0;
		for (int j = i; j < i + k; j++) {
			if (check[j] == true) cnt += 1;
		}
		if (ans > cnt)
			ans = cnt;
	}
	printf("%d\n", ans);
	return 0;
}