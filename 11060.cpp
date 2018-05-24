#include <iostream>
#include <algorithm>
using namespace std;
int inf = -1e+9;
int arr[1010];
int d[1010];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++) d[i] = inf;
	
	d[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = arr[i]; j > 0; j--) {
			if (d[i + j] == inf) d[i + j] = d[i] + 1;
			else d[i + j] = min(d[i + j], d[i] + 1);
		}
	}
	if (d[n] < 0) puts("-1");
	else printf("%d\n", d[n]);
	return 0;
}