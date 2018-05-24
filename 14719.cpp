#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[505];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &arr[i]);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		int start = 0;
		int end = 0;
		for (int j = 0; j < m; j++) {
			if (arr[j] >= i) {
				cnt += 1;
				if (cnt == 1) start = j;
				if (cnt == 2) {
					end = j;
					cnt = 0;
					for (int k = start; k <= j; k++) {
						if (arr[k] >= i) continue;
						ans += 1;
					}
					j--;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}