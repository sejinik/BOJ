#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k;
int a[101];
int d[10010];

int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	d[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j >= a[i] && d[j - a[i]] != -1) {
				if (d[j] == -1 || d[j] > d[j - a[i]] + 1) {
					d[j] = d[j - a[i]] + 1;
				}
			}
		}
	}
	printf("%d\n", d[k]);
	return 0;
}