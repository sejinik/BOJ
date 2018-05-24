#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[100010], b[100010], acnt, bcnt, ans = 1e9;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	int n; scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf(" %d", &x);
		if (x < 0) a[acnt++] = x;
		else b[bcnt++] = x;
	}
	sort(a, a + acnt,cmp);
	sort(b, b + bcnt);
	if (acnt == 0) printf("%d %d\n", b[0], b[1]);
	else if (bcnt == 0) printf("%d %d\n", a[1], a[0]);
	else {
		int l = 0, r = 0, lpos = 0, rpos = 0;
		while (l < acnt && r < bcnt) {
			int c = a[l] + b[r];
			if (abs(c) < ans) {
				lpos = l, rpos = r;
				ans = abs(c);
			}
			if (c < 0) r++;
			else if (c > 0) l++;
			else break;
		}
		printf("%d %d\n", a[lpos], b[rpos]); 
	}
	return 0;
}