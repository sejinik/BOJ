#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int d[10 * 25][(1 << 10)];
char map[25][25];
int n, m;

int go(int pos, int state) {
	if (pos >= n*m) return 0;
	int&ret = d[pos][state];
	if (ret != -1) return ret;
	ret = go(pos + 1, (state >> 1));
	int x = pos / n;
	int y = pos%n;
	if (map[x][y] != '1') {
		if (!(state & 1)) {
			ret = max(ret, go(pos + 1, (state >> 1)) + 1);
		}
		if (x != (m - 1) && y != (n - 1) && !(state&1) && !(state&2)) {
			if(map[x + 1][y] == '.' && map[x][y + 1] == '.' && map[x + 1][y + 1] == '.')
				ret = max(ret, go(pos + 2, (state >> 2) | (1 << (n - 1)) | (1 << (n - 2))) + 16);
		}
	}
	else ret += 1;
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &map[j][i]);
		}
	}
	printf("%d\n", go(0, 0));
	return 0;
}