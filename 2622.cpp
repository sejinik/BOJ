#include <iostream>
using namespace std;
int n,ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int c = n - i - j;
			if (c < j) break;
			if (c < i + j) ans++;
		}
	}
	printf("%d\n", ans);
}