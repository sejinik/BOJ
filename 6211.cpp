#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define inf -1e9
int d[22][35050];
int arr[22];
int n, m;

int go(int pos,int w) {
	if (w > m) return inf;
	if (pos == n) return 0;
	int&ret = d[pos][w];
	if (ret != -1) return ret;
	ret = inf;
	return ret = max(go(pos + 1, w), go(pos + 1, w + arr[pos])+arr[pos]);
}
int main() {
	memset(d, -1, sizeof(d));
	scanf(" %d %d", &m, &n);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	printf("%d\n", go(0, 0));
}