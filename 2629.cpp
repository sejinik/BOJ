#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int d[33][40040];
int n, k;

int main() {
	scanf("%d", &n);
	d[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int a; scanf(" %d", &a);
		for (int j = 0; j <= 40000; j++) {
			d[i][j + a] |= d[i - 1][j];
			 d[i][abs(j - a)] |= d[i - 1][j];
			 d[i][j] |= d[i - 1][j];
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a; scanf("%d", &a);
		if (d[n][a]) printf("Y ");
		else printf("N ");
	}
	puts("");
}