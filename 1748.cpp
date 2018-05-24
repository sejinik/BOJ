#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int SIZE(int n) {
	int ret = 0;
	
	while (n > 0) {
		n /= 10;
		ret += 1;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	int size = SIZE(n);
	int temp = size-1;

	int ans = 0;
	int minus = 0;
	for (int i = temp; i > 0; i--) {
		ans += (i * 9 * pow(10, i-1));
		minus += 9 * pow(10, i - 1);
	}

	temp = n - minus;
	ans += size*temp;
	printf("%d\n", ans);
	return 0;
	
}