#include <iostream>
#include <algorithm>
using namespace std;
int d[111];
pair<int, int> arr[111];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d", &arr[i].first, &arr[i].second);
	sort(arr + 1, arr + 1 + n);
	
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j].second <= arr[i].second) d[i] = max(d[i], d[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, d[i]);
	printf("%d\n", n - ans);
	return 0;
}