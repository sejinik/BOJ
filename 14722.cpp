#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int map[1010][1010];
int d[1010][1010][3];

int go(int x, int y, int milk) {
	if (x >= n || y >= n) return 0;
	int &ret = d[x][y][milk];
	if (ret != -1) return ret;
	
	ret = 0;
	if (map[x][y] == milk)
		return ret = max(go(x + 1, y, (milk + 1) % 3), go(x, y + 1, (milk + 1) % 3))+1;
	return ret = max(go(x + 1, y, milk), go(x, y + 1, milk));
}

int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d\n", go(0, 0, 0));	
	return 0;
}