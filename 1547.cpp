#include <iostream>
#include <algorithm>
using namespace std;
int arr[4];
int main() {
	int n; scanf("%d", &n);
	arr[1] = 1;
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b); swap(arr[a], arr[b]);
	}
	for (int i = 1; i <= 3; i++)
		if (arr[i]) printf("%d\n", i);
	return 0;
}