#include <iostream>
#include <algorithm>
using namespace std;
bool prime[4000040];
int arr[300000];
int pn;
int n;

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		if (!prime[i]) {
			arr[pn++] = i;
			for (int j = i * 2; j <= n; j += i)
				prime[j] = true;
		}
	}

	int right = 0;
	int left = 0;
	int sum = arr[0];
	int ans = 0;

	while (left <= right && right < pn) {
		if (sum == n) {
			ans += 1;

			right += 1;
			sum += arr[right];
		}
		else if (sum < n) {
			right += 1;
			sum += arr[right];
		}
		else {
			sum -= arr[left];
			left += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}