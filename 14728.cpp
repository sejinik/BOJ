#include <iostream>
#include <algorithm>	
#include <cstring>
using namespace std;
int n, t;
int d[101][10010];
int k[1010];
int s[1010];

int go(int x, int y) {
	if (x < 0 || y < 0) return 0;
	int & ret = d[x][y];
	if (ret != -1) return ret;
	if (y >= k[x])
		return ret = max(go(x - 1, y), go(x - 1, y - k[x]) + s[x]);
	else
		return ret = go(x - 1, y);
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &k[i], &s[i]);
	}
	printf("%d\n", go(n - 1, t));
	return 0;
}