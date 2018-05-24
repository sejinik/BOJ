#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int black[1111];
int white[1111];
int cnt;
int d[1111][33][33];

int go(int x, int bcnt, int wcnt) {
	if (bcnt < 0 || wcnt < 0) return -1e9;
	if (bcnt == 0 && wcnt == 0) return 0;
	if (x >= cnt) return -1e9;
	int&ret = d[x][bcnt][wcnt];
	if (ret != -1)return ret;
	ret = -1e9;
	return ret = max({ ret, go(x + 1,bcnt - 1,wcnt) + black[x],go(x + 1,bcnt,wcnt - 1) + white[x],go(x + 1,bcnt,wcnt) });

}

int main() {
	memset(d, -1, sizeof(d));
	//freopen("input.txt", "r", stdin);
	int a, b;
	int ww = 0;
	while (scanf(" %d %d", &a, &b) != -1) {
		white[cnt] = a;
		black[cnt++] = b;
	}
	printf("%d\n", go(0, 15, 15));
}