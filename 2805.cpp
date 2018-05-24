#include <cstdio>

int n, m;
int arr[1000010];

bool check(long long mid) {
	long long high = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > mid)
			high += arr[i] - mid;
	}

	return high >= m;
}
int main() {
	scanf("%d %d", &n, &m);
	
	int max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (max < arr[i])
			max = arr[i];
	}

	long long left = 0;
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