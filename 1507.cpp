#include <cstdio>
int n, m;
int d[22][22];
int arr[22][22];


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &d[i][j]);
			arr[i][j] = d[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == k || k == j) continue;
				if (d[i][j] == d[i][k] + d[k][j]) {
					d[i][j] = 10000000;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] == 10000000) continue;
			sum += d[i][j];
		}
	}
	sum /= 2;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	bool check = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != d[i][j]) check = false;
		}
	}
	if (check) printf("%d\n", sum);
	else puts("-1");
	return 0;
}