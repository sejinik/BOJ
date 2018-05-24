#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[1010];
int b[1010];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);;
	}

	sort(arr, arr + n);
	b[0] = arr[0];

	int sum = b[0];
	for (int i = 1; i < n; i++) {
		b[i] = arr[i] + b[i - 1];
		sum += b[i];
	}
	printf("%d\n", sum);
	return 0;
}