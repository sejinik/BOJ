#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll n, b, c,ans;
ll arr[1000100];

int main() {

	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	scanf("%lld %lld", &b, &c);
	ans += n;
	for (int i = 0; i < n; i++) {
		arr[i] -= b;
		if (arr[i] < 0) arr[i] = 0;
		if (arr[i] == 0) continue;

		if ((arr[i] % c) > 0) ans += (arr[i] / c) + 1;
		else ans += (arr[i] / c);
	}
	printf("%lld\n", ans);
	return 0;
}