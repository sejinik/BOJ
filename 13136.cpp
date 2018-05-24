#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
ll n, m, k;

int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	ll a = n / k + (n%k == 0 ? 0 : 1);
	ll b = m / k + (m%k == 0 ? 0 : 1);
	printf("%lld\n", a*b);
}