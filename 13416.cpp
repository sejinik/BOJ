#include <iostream>
#include <algorithm>
using namespace std;
int t, n;
int main() {
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf(" %d", &n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int a, b, c; scanf(" %d %d %d", &a, &b, &c);
			ans = max({ ans,ans + a,ans + b,ans + c });
		}
		printf("%d\n", ans);
	}
}