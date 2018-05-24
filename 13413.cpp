#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int t, n, wc1, wc2, bc1, bc2;
string s, p;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cin >> s >> p;
		string c = "", d = "";
		for (int i = 0; i < n; i++) {
			if (s[i] == p[i]) continue;
			c += s[i];
			d += p[i];
		}
		int m = c.size();
		int w1 = 0, w2 = 0;
		for (int i = 0; i < m; i++) {
			if (c[i] == 'W') w1++;
			if (d[i] == 'W') w2++;
		}
		if (w1 == c.size() || w2 == d.size()) printf("%d\n", c.size());
		else {
			int ans = abs(w1 - w2);
			m -= abs(w1 - w2);
			ans += m / 2;
			printf("%d\n", ans);
		}
	}
}