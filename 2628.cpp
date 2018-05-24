#include <iostream>
#include <algorithm>
using namespace std;
int r[111], l[111],k,rcnt=1,lcnt=1,ans;
int main() {
	int n, m; scanf("%d %d", &n, &m);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a, b; scanf(" %d %d", &a, &b);
		if (a) l[lcnt++] = b;
		else r[rcnt++] = b;
	}
	l[lcnt++] = n;
	r[rcnt++] = m;
	sort(l, l + lcnt);
	sort(r, r + rcnt);
	for (int i = 0; i < rcnt-1; i++) {
		for (int j = 0; j < lcnt-1; j++) {
			int c = (r[i + 1] - r[i]) *(l[j + 1] - l[j]);
			ans = max(ans, c);
		}
	}
	printf("%d\n", ans);
}