#include <iostream>
using namespace std;
bool map[111][111];

int main() {
	for (int i = 0; i < 4; i++) {
		int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int j = a; j < c; j++) {
			for (int k = b; k < d; k++) {
				map[j][k] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (map[i][j]) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}