#include <iostream>
#include <cstring>
using namespace std;
#define MOD 10007
int n, k;
int d[1010][1010];

int go(int x, int y) {
	if (y == 0 || x == y) return 1;
	int &ret = d[x][y];
	if (ret != -1) return ret;
	ret = go(x - 1, y - 1) + go(x - 1, y);
	ret %= MOD;
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d", &n, &k);
	printf("%d\n", go(n, k));
	return 0;
}