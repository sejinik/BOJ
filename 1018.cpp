#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, m, ans = 987654321;
char arr[55][55];
char bch[9][9];
char wch[9][9];

int bgo(int x, int y) {
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (bch[i][j] == arr[i + x][j + y]) ret += 1;
		}
	}
	return ret;
}

int wgo(int x, int y) {
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (wch[i][j] == arr[i + x][j + y]) ret += 1;
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					wch[i][j] = 'W';
					bch[i][j] = 'B';
				}
				else {
					wch[i][j] = 'B';
					bch[i][j] = 'W';
				}
			}
			else {
				if (j % 2 == 0) {
					wch[i][j] = 'B';
					bch[i][j] = 'W';
				}
				else {
					wch[i][j] = 'W';
					bch[i][j] = 'B';
				}
			}
		}
	}
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int w = wgo(i, j);
			int b = bgo(i, j);
			ans = min({ ans,w,b });
		}
	}
	cout << ans << "\n";
	return 0;
}