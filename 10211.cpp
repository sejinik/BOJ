#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,t;
int d[1010];
int arr[1010];

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		memset(d, 0, sizeof(d));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		d[1] = arr[1];
		for (int i = 2; i <= n; i++) {
			d[i] = arr[i];
			d[i] = max(d[i], d[i - 1] + arr[i]);
		}

		int ans = d[1];
		for (int i = 1; i <= n; i++) ans = max(ans, d[i]);
		printf("%d\n", ans);
	}
	return 0;
}