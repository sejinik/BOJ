#include <iostream>
#include <algorithm>
using namespace std;
int d, n, m;
int arr[50050];

bool go(int mid) {
	int ret = 0;
	int pos = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] - pos < mid) ret++;
		else pos = arr[i];
	}
	return ret <= m;
}
int main() {
	scanf(" %d %d %d", &d, &n, &m);
	arr[0] = 0;
	arr[n + 1] = d;
	for (int i = 1; i <= n; i++) scanf(" %d", &arr[i]);
	n += 2;
	sort(arr, arr + n);
	int left = 0, right = 1e9 + 1, ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (go(mid)) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%d\n", ans);
}