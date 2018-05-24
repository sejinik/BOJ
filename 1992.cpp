#include <iostream>
#include <algorithm>
using namespace std;
int map[66][66];

void go(int x, int y, int len) {
	if (len < 0) return;

	int sum = 0;
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			sum += map[i][j];
		}
	}
	if (sum == len*len) {
		printf("1"); return;
	}
	else if (sum == 0) {
		printf("0"); return;
	}
	else {
		printf("(");
		go(x, y, len / 2);
		go(x, y + len / 2, len / 2);
		go(x + len / 2, y, len / 2);
		go(x + len / 2, y + len / 2, len / 2);
		printf(")");
	}
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	go(1, 1, n);
	printf("\n");
	return 0;
}