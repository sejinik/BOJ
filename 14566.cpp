#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[5005];


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);

	int mini = 33333333;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i + 1] - arr[i] < mini)
			mini = arr[i + 1] - arr[i];
	}

	int left = 0;
	int right = 1;
	int ans = 0;
	while (left <= right) {
		if (right > n) break;
		if (left == right) right += 1;

		if (arr[right] - arr[left] >= mini) {
			if (arr[right] - arr[left] == mini)	 ans += 1;
			left += 1;
		}
		else
			right += 1;
	}
	printf("%d %d\n",mini, ans);
	return 0;
}