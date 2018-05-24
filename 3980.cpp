#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int d[(1 << 11)][11];
int arr[11][11];
int t;

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(d, -0x3f, sizeof(d));
		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				scanf(" %d", &arr[i][j]);
			}
		}

		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < (1 << 11); j++) {
				for (int k = 0; k < 11; k++) {
					if (!(j&(1 << k)) && arr[i][k]) {
						if (i == 0) d[j | (1 << k)][i] = max(d[j | (1 << k)][i], arr[i][k]);
						else d[j | (1 << k)][i] = max(d[j | (1 << k)][i], d[j][i - 1] + arr[i][k]);
					}
				}
			}
		}
		printf("%d\n", (d[(1 << 11) - 1][10]));
	}
	return 0;
}