#include <iostream>
#include <algorithm>
using namespace std;
int p[10010];
int m[10010];
int z[10010];
int o[10010];
int n,pc,mc,zc,oc;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num; scanf("%d", &num);
		if (num == 0) z[zc++] = num;
		else if (num == 1) o[oc++] = num;
		else if (num > 1) p[pc++] = num;
		else m[mc++] = num;
	}
	int ans = 0;
	sort(p, p + pc);
	sort(m, m + mc);
	reverse(p, p + pc);
	for (int i = 0; i +1 < pc; i += 2) ans += p[i] * p[i + 1];
	if (pc & 1) ans += p[pc-1];
	for (int i = 0; i + 1 < mc; i += 2) ans += m[i] * m[i + 1];
	if (mc & 1) {
		if (zc == 0) ans += m[mc - 1];
	}
	ans += oc;
	printf("%d\n", ans);
	return 0;
}