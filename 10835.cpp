#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int rcard[2020];
int lcard[2020];
int d[2020][2020];

int go(int x, int y) {
	if (x >=n || y >= n) return 0;
	int& ret = d[x][y];
	if (ret != -1) return ret;

	if (lcard[x] > rcard[y]) {
		return ret = max({ go(x + 1,y),go(x,y + 1)+rcard[y],go(x + 1,y + 1) });
	}
	else
		return ret = max(go(x + 1, y), go(x + 1, y + 1));
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &lcard[i]);
	for (int i = 0; i < n; i++) scanf("%d", &rcard[i]);
	printf("%d\n", go(0, 0));
	return 0;
}