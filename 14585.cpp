#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int d[303][303];
bool arr[303][303];
int n, m;

int go(int x, int y) {
	if (x >= 301 || y >= 301) return 0;
	int&ret = d[x][y];
	if (ret != -1) return ret;
	int cnt = (arr[x][y]==true) ? max(0,m - x - y) : 0;
	ret = max(go(x + 1, y), go(x, y + 1)) + cnt;
	return ret;
}

int main() {
	memset(d, -1, sizeof(d));
	scanf(" %d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x, y; scanf(" %d %d", &x, &y);
		arr[x][y] = true;
	}
	printf("%d\n", go(0, 0));

}