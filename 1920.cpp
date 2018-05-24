#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[100010];
int arr2[100010];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr2[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < m; i++) {
		printf("%d\n", binary_search(arr, arr + n, arr2[i]));
	}
	return 0;
}