#include <iostream>
#include <algorithm>
using namespace std;
int n, m,x,y,k;
int map[22][22];
int cube[7];
int ncube[7];

void go(int pos) {
	if (pos == 1) {
		ncube[6] = cube[2]; ncube[4] = cube[6];
		ncube[5] = cube[4]; ncube[2] = cube[5];
		ncube[1] = cube[1];	ncube[3] = cube[3];
	}
	else if (pos == 2) {
		ncube[5] = cube[2]; ncube[4] = cube[5];
		ncube[6] = cube[4]; ncube[2] = cube[6];
		ncube[1] = cube[1]; ncube[3] = cube[3];
	}
	else if (pos == 3) {
		for (int i = 1; i <= 3; i++) ncube[i] = cube[i + 1];
		ncube[4] = cube[1];
	}
	else {
		for (int i = 2; i <= 4; i++) ncube[i] = cube[i - 1];
		ncube[1] = cube[4];
	}
	for (int i = 1; i <=6; i++) cube[i] = ncube[i];
}
int main() {
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (k--) {
		int pos; scanf("%d", &pos);
		if (pos == 1) {
			if (y + 1 >= m) continue;
			y += 1; go(1);
		}
		else if (pos == 2) {
			if (y - 1 < 0) continue;
			y -= 1; go(2);
			
		}
		else if (pos == 3) {
			if (x - 1 < 0) continue;
			x -= 1; go(3);
		}
		else {
			if (x + 1 >= n) continue;
			x += 1; go(4);
		}
		if (map[x][y] == 0) map[x][y] = cube[4];
		else cube[4] = map[x][y], map[x][y] = 0;
		printf("%d\n", cube[2]);
	}
	return 0;
}