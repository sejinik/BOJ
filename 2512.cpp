#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long m;
long long arr[100010];
long long left, right, ans;

bool go(long long mid) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (mid > arr[i])
			sum += arr[i];
		else
			sum += mid;
	}

	if (sum <= m) return true;
	else
		return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		right = max(right, arr[i]);
	}
	scanf("%lld", &m);

	left = ans = 0;
	while (left <= right) {
		long long mid = (right + left) / 2;
		if (go(mid)) {
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	printf("%lld\n", ans);
}