#include <iostream>
#include <algorithm>
using namespace std;
int arr[111];
int n,k;
int main() {
	scanf(" %d", &n);
	for (int i = 1; i <= n; i++) scanf(" %d", &arr[i]);
	scanf(" %d", &k);
	for (int i = 0; i < k; i++) {
		int a, b; scanf(" %d %d", &a, &b);
		if (a == 1) {
			for (int j = 1; j <= n; j++)
				if (j%b == 0) arr[j] = (arr[j] + 1) % 2;
		}
		else {
			int prev = b;
			int next = b;
			while (arr[prev - 1] == arr[next + 1] && 1<=prev-1 && next+1<=n) {
				prev--;
				next++;
			}
			for (int j = prev; j <= next; j++) arr[j] = (arr[j]+1)%2;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
		if (i % 20 == 0) puts("");
	}
}