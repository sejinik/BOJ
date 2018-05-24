#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
ll n, k, ans;
int main() {
	scanf(" %lld %lld", &n, &k);
	for (int i = 0, j = 0; j < 32; i++, j++) {
		while (n&(1LL << i)) i++;
		if (k&(1LL << j)) ans += (1LL << i);
	}
	printf("%lld\n", ans);
}