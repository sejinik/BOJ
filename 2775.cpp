#include <iostream>
using namespace std;

int d[15][15];
int tcase, a, b;

int main() {

	for (int i = 0; i < 15; i++) {
		d[0][i] = i;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
			}
		}
	}
	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", d[a][b]);
	}
	return 0;
}