#include <cstdio>

int n,m;
int d[2002][2002];
int arr[2002];

bool go(int x, int y) {
	if (x == y) return 1;
	if (x + 1 == y) {
		if (arr[x] == arr[y]) return true;
		return false;
	}

	int& ret = d[x][y];
	if (ret == 1) return true;

	if (arr[x] == arr[y]) ret = go(x + 1, y - 1);

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &m);

	while (m--) {
		int s, e;
		scanf("%d%d", &s, &e);
		printf("%d\n", go(s, e));
	}
	return 0;
}