#include <iostream>
#include <algorithm>
using namespace std;
int n;
double arr[10010];
double d[10010],ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lf", &arr[i]);

	for (int i = 0; i < n; i++) {
		ans = 1.0;
		for (int j = i; j >= 0; j--) {
			ans *= arr[j];
			d[i] = max(d[i], ans);
		}
	}
	ans = 0.0;
	for (int i = 0; i < n; i++) ans = max(ans, d[i]);
	printf("%.3lf\n", ans); return 0;
}