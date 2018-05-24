#include <iostream>
#include <algorithm>
using namespace std;
#define INF 2000000000
#define ll long long
ll n, m;
ll ratio(ll b, ll a) {
	return (a * 100) / b;
}
int main() {
	while (scanf("%lld %lld", &n, &m) != -1) {
		ll right = INF, left = 0;
		if (ratio(n, m) == ratio(n + right, m + right)) {
			puts("-1"); continue;
		}
		while (left <= right) {
			ll mid = (left + right) / 2;
			if (ratio(n, m) == ratio(n + mid, m + mid)) left = mid + 1;
			else right = mid - 1;
		}
		printf("%lld\n", left);
	}
}