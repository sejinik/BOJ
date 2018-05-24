#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, k, arr[111];
priority_queue<int> pq;
int main() {
	scanf(" %d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	for (int i = 0; i < n; i++) {
		int x; scanf(" %d", &x);
		int maxn = -1e9;
		for (int j = 0; j < n; j++) {
			maxn = max(maxn, x*arr[j]);
		}
		pq.push(maxn);
	}
	while (k--) pq.pop();
	printf("%d\n", pq.top());
}