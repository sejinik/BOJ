#include <iostream>
#include <algorithm>
using namespace std;

int d[501][501];
int a[501][501];

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	d[1][1] = a[1][1];

	for (int i = 2; i <= num; i++) {
		d[i][1] = d[i - 1][1] + a[i][1];
		d[i][i] = d[i - 1][i - 1] + a[i][i];
		for (int j = 2; j < i; j++) {
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i <= num; i++) {
		ans = max(ans, d[num][i]);
	}
	printf("%d\n", ans);
	return 0;
}