#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m, ox, oy, rx, ry, bx, by;
int inf = 1e+9;
int ans = 1e+9;
char map[22][22];
void E() {
	if (by < ry) {
		while (map[rx][ry + 1] != '#') {
			ry += 1; if (map[rx][ry] == 'O') break;
		}
		while (map[bx][by + 1] != '#') {
			if ((rx == bx) && (ry == by + 1)) {
				if (map[bx][by + 1] != 'O') break;
			}
			by += 1; if (map[bx][by] == 'O') break;
		}
	}
	else {
		while (map[bx][by + 1] != '#') {
			by += 1; if (map[bx][by] == 'O') break;
		}
		while (map[rx][ry + 1] != '#') {
			if ((rx == bx) && (ry + 1 == by)) {
				if(map[rx][ry+1] != 'O') break;
			}
			ry += 1; if (map[rx][ry] == 'O') break;
		}
	}
}
void W() {
	if (by < ry) {
		while (map[bx][by - 1] != '#') {
			by -= 1; if (map[bx][by] == 'O') break;
		}
		while (map[rx][ry - 1] != '#') {
			if ((rx == bx) && (ry - 1 == by)) {
				if(map[rx][ry-1] != 'O') break;
			}
			ry -= 1; if (map[rx][ry] == 'O') break;
		}
	}
	else {
		while (map[rx][ry - 1] != '#') {
			ry -= 1; if (map[rx][ry] == 'O') break;
		}
		while (map[bx][by - 1] != '#') {
			if ((rx == bx) && (ry == by - 1)) {
				if(map[bx][by-1] != 'O') break;
			}
			by -= 1; if (map[bx][by] == 'O') break;
		}
	}
}
void N() {
	if (bx < rx) {
		while (map[rx + 1][ry] != '#') {
			rx += 1; if (map[rx][ry] == 'O') break;
		}
		while (map[bx + 1][by] != '#') {
			if ((rx == bx + 1) && (ry == by)) {
				if (map[bx + 1][by] != 'O') break;
			}
			bx += 1; if (map[bx][by] == 'O') break;
		}
	}
	else {
		while (map[bx + 1][by] != '#') {
			bx += 1; if (map[bx][by] == 'O') break;
		}
		while (map[rx + 1][ry] != '#') {
			if ((rx + 1 == bx) && (ry == by)) {
				if(map[rx+1][ry] != 'O') break;
			}
			rx += 1; if (map[rx][ry] == 'O') break;
		}
	}
}
void S() {
	if (bx < rx) {
		while (map[bx - 1][by] != '#') {
			bx -= 1; if (map[bx][by] == 'O') break;
		}
		while (map[rx - 1][ry] != '#') {
			if ((rx - 1 == bx) && (ry == by)) {
				if (map[rx - 1][ry] != 'O')	break;
			}
			rx -= 1; if (map[rx][ry] == 'O') break;
		}
	}
	else {
		while (map[rx - 1][ry] != '#') {
			rx -= 1; if (map[rx][ry] == 'O') break;
		}
		while (map[bx - 1][by] != '#') {
			if ((rx == bx - 1) && (ry == by)) {
				if(map[bx-1][by] != 'O') break;
			}
			bx -= 1; if (map[bx][by] == 'O') break;
		}
	}
}

void go(int Rx, int Ry, int Bx, int By, int cnt) {
	if (cnt > 10) return;
	if (map[Bx][By] == 'O') return;
	if (map[Rx][Ry] == 'O') {
		ans = min(ans, cnt); return;
	}

	E(); go(rx, ry, bx, by, cnt + 1);
	rx = Rx; ry = Ry; bx = Bx; by = By;

	W();	go(rx, ry, bx, by, cnt + 1);
	rx = Rx; ry = Ry; bx = Bx; by = By;

	N(); go(rx, ry, bx, by, cnt + 1);
	rx = Rx; ry = Ry; bx = Bx; by = By;

	S(); go(rx, ry, bx, by, cnt + 1);
	rx = Rx; ry = Ry; bx = Bx; by = By;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'R') rx = i, ry = j;
			if (map[i][j] == 'B') bx = i, by = j;
			if (map[i][j] == 'O') ox = i, oy = j;
		}
	}
	go(rx, ry, bx, by, 0);
	if (ans == inf) puts("-1");
	else printf("%d\n", ans);
	return 0;
}