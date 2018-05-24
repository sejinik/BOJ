#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char price[6][6] = {
	{100,70,40,0,0,0},
	{70,50,30,0,0,0},
	{40,30,20,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
};
char map[11][11];
int d[11 * 11][(1 << 11)];
int n;
int go(int pos, int state) {
	if (pos >= n*n) return 0;
	int&ret = d[pos][state];
	if (ret != -1) return ret;
	ret = go(pos + 1, (state >> 1));
	int x = pos / n;
	int y = pos%n;
	if (!(state & 1)) {
		if (x != n - 1) {
			int temp = go(pos + 1, (state >> 1) | (1 << (n - 1)));
			temp += price[map[x][y] - 'A'][map[x + 1][y]-'A'];
			ret = max(ret, temp);
		}
		if (y != n - 1 && (!(state & 2))) {
			int temp = go(pos + 2, (state >> 2));
			temp += price[map[x][y]-'A'][map[x][y + 1]-'A'];
			ret = max(ret, temp);
		}
	}
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
	printf("%d\n", go(0, 0));
	return 0;
}