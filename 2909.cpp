#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
	ll n, k; scanf("%lld %lld", &n, &k);
	if (k == 0) {
		printf("%lld\n", n); return 0;
	}
	k = pow(10, k);
	ll mod = (n%k);
	if (mod >= k / 2) n = n - mod + k;
	else n -= mod;
	printf("%lld\n", n);
	return 0;
}