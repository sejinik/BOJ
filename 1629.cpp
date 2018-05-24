#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long 
ll a, b, c;

ll go(ll x, ll y) {
	if (y == 0) return 1;
	if (y % 2 == 1)
		return x*(go(x, y - 1)) % c;
	return go((x*x) % c,y / 2)%c;
}
int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld\n", go(a, b));
	return 0;
}