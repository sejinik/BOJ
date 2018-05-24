#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool check[11][11];
int arr[11][11];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n;
int ans = 1000000000;

bool go(int x, int y) {
	if (check[x][y]) return false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int cnt = 0;
		
		if (nx >= n || nx < 0 || ny >= n || ny < 0) return false;
		if (check[nx][ny]) return false;
		check[nx][ny] = true;
	}
	return true;
}

int cost(int x, int y) {
	int ret = arr[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		ret += arr[nx][ny];
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			for (int c = 0; c < n; c++) {
				for (int d = 0; d < n; d++) {
					for (int e = 0; e < n; e++) {
						for (int f = 0; f < n; f++) {
							memset(check, 0, sizeof(check));
							if (go(a, b) && go(c, d) && go(e, f)) {
								ans = min(ans, cost(a, b) + cost(c, d) + cost(e, f));
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}