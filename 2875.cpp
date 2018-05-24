#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k;
int main() {
	scanf("%d %d %d", &n, &m, &k);
	int ans = min(n / 2, m);
	n -= ans * 2;
	m -= ans;
	while (n+m <k) {
		ans -= 1;
		n += 2;
		m += 1;
	}	
	printf("%d\n", ans);
}