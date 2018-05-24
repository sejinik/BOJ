#include <iostream>
using namespace std;
int n, m, k;
bool a[111], b[111], c[111];
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < 3; i++) {
		int x, y; scanf("%d %d", &x, &y);
		for (int j = x; j < y; j++) {
			if (i == 0) a[j] = true;
			else if (i == 1) b[j] = true;
			else c[j] = true;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		int cnt = a[i] + b[i] + c[i];
		if (cnt == 1) ans += n;
		else if (cnt == 2) ans += m*2;
		else if (cnt==3) ans += k*3;
	}
	printf("%d\n", ans);
}