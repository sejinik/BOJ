#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define INF 100000000
using namespace std;
int d[55][250050];
int arr[55];
int n;

int go(int pos, int diff){
	if (diff > 250000) return -INF;
	if (pos == n) {
		if (diff == 0) return 0;
		return -INF;
	}
	int&ret = d[pos][diff];
	if (ret != -1) return ret;
	ret = go(pos + 1, diff);
	ret = max(ret, go(pos + 1, diff + arr[pos]));
	if (arr[pos] > diff) ret = max(ret, go(pos + 1, arr[pos] - diff) + diff);
	else ret = max(ret, go(pos + 1, diff - arr[pos]) + arr[pos]);
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	int ans = go(0, 0);
	printf("%d\n", ans == 0 ? -1 : ans);
}