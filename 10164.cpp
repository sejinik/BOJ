#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, k;
int map[20][20];
int fd[20][20];
int sd[20][20];
int kx, ky;
int cnt = 1;

int fgo(int x, int y) {
	if (x > kx || y > ky) return 0;
	if (x == kx && y == ky) return 1;
	int & ret = fd[x][y];
	if (ret != -1) return	ret;
	ret = 0;
	ret += fgo(x + 1, y) + fgo(x, y + 1);
	return ret;
}
int sgo(int x, int y) {
	if (x >= n || y >= m) return 0;
	if (x == n - 1 && y == m - 1) return 1;
	int & ret = sd[x][y];
	if (ret != -1) return ret;
	ret = 0;
	ret += sgo(x + 1, y) + sgo(x, y + 1);
	return ret;
}
int main() {
	memset(sd, -1, sizeof(sd));
	memset(fd, -1, sizeof(fd));
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = cnt++;
			if (map[i][j] == k) kx = i, ky = j;
		}
	}
	if (k != 0) {
		int ans = fgo(0, 0) * sgo(kx, ky);
		printf("%d\n", ans);
	}
	else {
		printf("%d\n", sgo(0, 0));
	}

	
	return 0;
}