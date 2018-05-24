#include <iostream>
using namespace std;
#define ll long long
#define INF 2100000000
ll a, b, c;
ll cost(ll mid) {
	return a + b*mid;
}
int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	ll right = INF, left = 0;
	if (a + b*right > c*right) {
		puts("-1"); return 0;
	}
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (cost(mid) < c*mid) right = mid - 1;
		else left = mid + 1;
	}
	printf("%lld\n", left);
}