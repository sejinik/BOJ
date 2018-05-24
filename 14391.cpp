#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[5][5];
bool check[5][5];
int n, m,ans;

int score() {
	int ret = 0;
	int sc = 0;
	for (int i = 0; i < n; i++) {
		if (sc != 0) ret += sc, sc = 0;
		for (int j = 0; j < m; j++) {
			if (!check[i][j]) sc *= 10, sc += arr[i][j];
			else ret += sc, sc = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		if (sc != 0) ret += sc, sc = 0;
		for (int j = 0; j < n; j++) {
			if (check[j][i]) sc *= 10, sc += arr[j][i];
			else ret += sc, sc = 0;
		}
	}
	if (sc != 0) ret += sc;
	return ret;
}
int main() {
	scanf(" %d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < (1 << (n*m)); i++) {
		memset(check, 0, sizeof(check));
		for (int j = n*m-1; j >=0; j--) {
			if (i&(1 << j)) check[j / m][j%m] = true;
		}
		ans = max(ans, score());
	}
	printf("%d\n", ans);
}