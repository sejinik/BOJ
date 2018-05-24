#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e+9
int n, m;
int d[111][111];
int from[111][111];
queue<int> q;
void go(int here, int next) {
	int c = from[here][next];
	if (q.back() != here) q.push(here);
	if (c != -1) {
		go(here, from[here][next]);
		go(from[here][next], next);
	}
}
int main() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			d[i][j] = INF;
		}
	}
	memset(from, -1, sizeof(from));
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int x, y, z; scanf("%d %d %d", &x, &y, &z);
		d[x][y] = min(d[x][y], z);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					from[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == 0) {
				puts("0");
			}
			else {
				q.push(i);
				go(i, j);
				q.push(j);
				printf("%d", q.size());
				while (!q.empty()) {
					printf(" %d", q.front()); q.pop();
				}
				printf("\n");
			}
		}
	}
	
}