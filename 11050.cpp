#include <iostream>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int ans = 1;
	int ansk = 1;
	for (int i = 0; i < k; i++) {
		ans *= (n - i);
		ansk *= (k - i);
	}
	ans = ans / ansk;

	printf("%d\n", ans);
	return 0;
}