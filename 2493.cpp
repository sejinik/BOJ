#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[500050], d[500050];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	for (int i = 2; i <= n; i++) {
		if (arr[i] < arr[i - 1]) d[i] = i - 1;
		else {
			for (int j = i - 1; d[j]; j = d[j]) {
				if (arr[i] < arr[d[j]]) {
					d[i] = d[j]; break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", d[i]);
	puts("");
}