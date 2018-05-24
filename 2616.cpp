#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k;
int arr[80050];
int d[50050][3];

int go(int pos, int cnt) {
	if (pos >= n || cnt == 0) return 0;
	int&ret = d[pos][cnt];
	if (ret != -1) return ret;
	int c = ret = 0;
	for (int i = pos; i < pos + k; i++) c += arr[i];
	return ret = max(go(pos + 1, cnt), go(pos + k, cnt - 1) + c);
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	scanf("%d", &k);
	printf("%d\n", go(0, 3));
}