#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int d[111][1111];
int arr[111];
int n, s, m;
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d %d", &n, &s, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	if (s - arr[1] >= 0) d[1][s - arr[1]] = 1;
	if (s + arr[1] <= m) d[1][s + arr[1]] = 1;
	for (int i = 2; i <= n; i++) {
		for (int k = 0; k <= m; k++) {
			if (k - arr[i] >= 0) d[i][k] = max(d[i][k], d[i - 1][k - arr[i]]);
			if (k + arr[i] <= m) d[i][k] = max(d[i][k], d[i - 1][k + arr[i]]);
		}
	}
	int ans = -1;
	for (int i = 0; i <= m; i++) {
		if (d[n][i] != -1) ans = max(ans, i);
	}
	printf("%d\n", ans);
	
}