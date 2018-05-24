#include <cstdio>	
#include <algorithm>
using namespace std;

int n, m;
int arr[5005];

int go(int mid) {

	int cnt = 1;
	int max_num = arr[0];
	int min_num = arr[0];
	for (int i = 1; i < n; i++) {
		max_num = max(max_num, arr[i]);
		min_num = min(min_num, arr[i]);

		if (max_num - min_num > mid) {
			cnt += 1;
			max_num = min_num = arr[i];
		}
	}
	return cnt;
}

int main() {
	scanf("%d %d", &n, &m);
	
	int right = 0;
	int left = 0;
	int ans = 10000;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		right = max(right, arr[i]);
		left = min(left, arr[i]);
	}

		while (left <= right) {
			int mid = (left + right) / 2;
			if (go(mid) <= m) {
				if (ans > mid)
					ans = mid;
				right = mid - 1;
			}
			else
				left = mid + 1;
		}

	printf("%d\n", ans);
	return 0;
}