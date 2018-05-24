#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int arr[5050];
int d[5050][5050];

int go(int x, int y) {
	if (x >= y) return 0;
	int &ret = d[x][y];
	if (ret != -1) return ret;
	if (arr[x] == arr[y]) return ret = go(x + 1, y - 1);
	else return ret = min(go(x + 1, y), go(x, y - 1)) + 1;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	printf("%d\n", go(0, n - 1));
	return 0;
}