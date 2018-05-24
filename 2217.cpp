#include <iostream>
#include <algorithm>
using namespace std;
int arr[100010];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);

	int ans = 0;
	int pos = n;
	for (int i = 0; i < n; i++) {
		ans = max(ans, arr[i] * (pos--));
	}
	printf("%d\n", ans);
}