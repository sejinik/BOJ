#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
ll d[111][22];
ll arr[111];
ll n;

ll go(ll pos, ll sum) {
	if (pos >= n-1) return 0;
	if (sum < 0 || sum >20) return 0;
	if (pos == n - 2 && arr[n-1] == sum) return 1;
	ll &ret = d[pos][sum];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(pos + 1, sum + arr[pos+1]);
	ret += go(pos + 1, sum - arr[pos+1]);
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
	printf("%lld\n", go(0, arr[0]));
	return 0;
}