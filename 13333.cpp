#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1010];

int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	sort(arr, arr + n);
	
	for (int i = 0; i <= 10000; i++) {
		auto a = lower_bound(arr, arr + n, i) - arr;
		auto b = upper_bound(arr, arr + n, i) - arr;
		for (int j = a; j <= b; j++) {
			if (j > n) continue;
			if (i == n - j) {
				printf("%d\n", i); return 0;
			}
		}
	}
}