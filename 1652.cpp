#include <cstdio>

char arr[120][120];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &arr[i]);
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '.') {
				cnt += 1;
				if (j == n - 1) {
					if (cnt > 1) {
						ans += 1;
					}
				}
			}
			else if (arr[i][j] == 'X') {
				if (cnt > 1) {
					ans += 1;
				}
				cnt = 0;
			}
		}
	}

	int ans2 = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j][i] == '.') {
				cnt += 1;
				if (j == n - 1) {
					if (cnt > 1) {
						ans2 += 1;
					}
				}
			}
			else if (arr[j][i] == 'X') {
				if (cnt > 1) {
					ans2 += 1;
				}
				cnt = 0;
			}
		}
	}
	printf("%d %d\n", ans, ans2);
	return 0;
}