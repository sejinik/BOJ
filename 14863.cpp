#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int walk[111], walk_money[111], ride[111], ride_money[111];
int d[111][111111];
int n, k;

int go(int pos, int time) {
	if (pos == n) return 0;
	if (time <= 0) return -1e+9;
	int&ret = d[pos][time];
	if (ret != -1) return ret;
	ret = -1e+9;
	int c = time - walk[pos];
	if (c >= 0 && go(pos + 1, c) != -1e+9) ret = max(ret, go(pos + 1, c) + walk_money[pos]);
	c = time - ride[pos];
	if (c >= 0 && go(pos + 1, c) != -1e+9) ret = max(ret, go(pos + 1, c) + ride_money[pos]);
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d %d %d %d", &walk[i], &walk_money[i], &ride[i], &ride_money[i]);
	printf("%d\n", go(0, k));
	return 0;
}