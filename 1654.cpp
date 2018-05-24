#include <cstdio>

int arr[10010];
int n, k;

bool check(long long mid) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += arr[i] / mid;
	}

	return cnt >= k;
}
int main() {
	scanf("%d %d", &n, &k);
	int max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (max < arr[i])
			max = arr[i];
	}

	long long left = 1;
	long long right = max;
	long long ans = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (check(mid)) {
			if (ans < mid)
				ans = mid;

			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
	
}