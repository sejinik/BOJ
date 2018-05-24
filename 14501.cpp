#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int a[20];
int b[20];
int d[20];

int go(int x) {
	if (x >= n) return 0;
	int &ret = d[x];
	if (ret != -1) return ret;

	if ((x + a[x]) <= n)	 return ret = max(go(x + a[x]) + b[x], go(x + 1));
	return ret = max(ret, go(x + 1));
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}

	printf("%d\n", go(0));
	return 0;
}