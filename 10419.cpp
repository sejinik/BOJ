#include <iostream>
using namespace std;
int t;

int main() {
	scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (i + i*i <= n) ans += 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}