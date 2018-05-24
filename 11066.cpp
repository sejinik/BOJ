#include <iostream>
#include <cstring>
using namespace std;
int t, n;
int arr[505];
int s[505];
int d[505][505];

int go(int x, int y) {
	if (x == y) return 0;
	int &ret = d[x][y];
	
	if (ret != -1) return ret;
	for (int i = x; i < y; i++) {
		int temp = go(x, i) + go(i + 1, y) + s[y] - s[x - 1];
		if (ret == -1 || ret > temp)
			ret = temp;
	}
	return ret;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		memset(s, 0, sizeof(s));
		memset(d, -1, sizeof(d));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

		s[0] = arr[0];
		for (int i = 1; i < n; i++) {
			s[i] = s[i - 1] + arr[i];
		}
		printf("%d\n", go(0, n - 1));
	}
	return 0;
}