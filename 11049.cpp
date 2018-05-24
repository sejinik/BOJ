#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int arr[505][2];
int d[505][505];

int go(int x, int y) {
	if (x == y) return 0;
	if (x + 1 == y) return arr[x][0] * arr[x][1] * arr[y][1];

	int &ret = d[x][y];
	if (ret != -1) return ret;

	for (int k = x; k < y; k++) {
		int t1 = go(x, k);
		int t2 = go(k + 1, y);
		if (ret == -1 || ret > t1 + t2 + arr[x][0] * arr[k][1] * arr[y][1])
			ret = t1 + t2 + arr[x][0] * arr[k][1] * arr[y][1];
	}
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	printf("%d\n", go(0, n - 1));
	return 0;
}