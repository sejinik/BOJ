#include <cstdio>
#include <cstring>
using namespace std;

int n;
int arr[101][101];
long long d[101][101];

long long go(int x, int y) {
	if (x == 0 && y == 0) return 1;

	long long& ret = d[x][y];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 1; i < n; i++) {
		if (i == arr[x][y - i])
			ret += go(x, y - i);

		if (i == arr[x - i][y])
			ret += go(x - i, y);
	}

	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	memset(d, -1, sizeof(d));

	printf("%lld\n", go(n - 1, n - 1));
	return 0;
}