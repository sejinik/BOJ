#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[3000000], sum[3000000], ans[3000000];
int n;

int main() {
	scanf(" %d", &n);
	int size = (1 << (n + 1)) - 1;
	int m = 0;
	int rans = 0;
	for (int i = 2; i <= size; i++) {
		scanf(" %d", &arr[i]);
		rans += arr[i];
		sum[i] += arr[i];

		if (i * 2 <= size) sum[i * 2] += sum[i];
		if (i * 2 + 1 <= size) sum[i * 2 + 1] += sum[i];
		m = max(m, sum[i]);
	}

	int start = (1 << n);
	for (int i = start; i <= size; i++) ans[i] = m - sum[i];
	for (int i =start-1; i > 0; i--) {
		ans[i] = min(ans[i*2], ans[i*2 + 1]);
		ans[i*2] -= ans[i];
		ans[i*2 + 1] -= ans[i];
		if (ans[i*2] < 0) ans[i*2] = 0;
		if (ans[i*2 + 1] < 0) ans[i*2 + 1] = 0;
	}
	for (int i = 1; i <= size; i++) rans += ans[i];
	printf("%d\n", rans);
}