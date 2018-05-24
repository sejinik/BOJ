#include <cstdio>
#include <algorithm>
using namespace std;

int n, c;
int arr[200010];

bool check(int mid) {
	int cnt = 1;
	int last = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] - last >= mid) {
			cnt += 1;
			last = arr[i];
		}
	}
	
	return cnt >= c;
}
int main() {
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[i] = temp;
	}
	
	sort(arr, arr + n);

	int right = arr[n-1] - arr[0];
	int left = 1;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (check(mid)) {
			if (ans < mid)
				ans = mid;

			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	printf("%d\n", ans);
	return 0;
}