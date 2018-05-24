#include <iostream>
using namespace std;

bool prime[1000010];
int num[1000010];
int cnt;
int n;

int main() {
	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		if (!prime[i]) {
			num[cnt++] = i;

			for (int j = i * 2; j <= n; j += i) {
				prime[j] = true;
			}
		}
	}

	if (n % 2 == 0) {
		n -= 4;

		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < cnt; j++) {
				if (num[i] + num[j] == n) {
					printf("%d %d %d %d\n", 2, 2, num[i], num[j]);
					return 0;
				}
			}
		}
		printf("-1\n");
	}

	else if (n <= 7) {
		printf("-1\n");
	}
	else {
		n -= 5;

		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < cnt; j++) {
				if (num[i] + num[j] == n) {
					printf("%d %d %d %d\n", 2, 3, num[i], num[j]);
					return 0;
				}
			}
		}
		printf("-1\n");
	}

	return 0;
}