#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int A[55][55];
int B[55][55];

void go(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			A[i][j] = (A[i][j] + 1) % 2;
		}
	}
}
bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j]) return false;
		}
	}
	return true;
}

int main() {
	scanf(" %d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1d", &A[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1d", &B[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m-2; j++) {
			if (A[i][j] != B[i][j]) {
				cnt++;
				go(i, j);
			}
		}
	}
	if (check()) printf("%d\n", cnt);
	else puts("-1");
}