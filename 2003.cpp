#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[10010];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int left = 0;
	int right = 0;
	int ans = arr[0];
	int cnt = 0;

	while (left <= right && right<n) {
		if (ans == m) {
			cnt += 1;
			if (left == right) {
				left += 1;
				right += 1;
				ans = arr[left];
			}
			else {
				ans -= arr[left];
				left += 1;
			}
		}
		else if (ans > m) {
			if (left == right) {
				left += 1;
				right += 1;
				ans = arr[left];
			}
			else {
				ans -= arr[left];
				left += 1;
			}
		}
		else {
			right += 1;
			ans += arr[right];
		}
	}
	printf("%d\n", cnt);
	return 0;
}