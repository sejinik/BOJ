#include <iostream>
#include <cstring>
using namespace std;
int t, n, money;
int d[10010];
int arr[22];

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(d, 0, sizeof(d));
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		scanf("%d", &money);
		d[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = arr[i]; j <= money; j++)
				d[j] += d[j - arr[i]];
		}
		printf("%d\n", d[money]);
	}
	return 0;
}