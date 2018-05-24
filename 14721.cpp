#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n;
int arr[111];

int gcd(int x, int y) {
	if (y == 0) return x;
	 return gcd(y, x%y);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int temp = gcd(arr[i], arr[j]);
				ans += temp;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}