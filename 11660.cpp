#include <iostream>
#include <algorithm>
using namespace std;
int arr[1030][1030];
int s[1030][1030];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", s[c][d] - s[c][b - 1] - s[a - 1][d] + s[a - 1][b - 1]);
	}
	return 0;
}