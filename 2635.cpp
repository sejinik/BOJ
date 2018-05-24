#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	int ans = 0;
	int pos = 0;
	for (int i = n; i >= n / 2; i--) {
		int c = n;
		int num = i;
		int cnt = 1;
		while (c >= 0) {
			cnt++;
			c -= num;
			swap(c, num);
		}
		if (ans <= cnt) ans = cnt, pos = i;
	}
	ans--;
	printf("%d\n", ans);
	while (n >= 0) {
		printf("%d ", n);
		n -= pos;
		swap(n, pos);
	}
	puts("");
}