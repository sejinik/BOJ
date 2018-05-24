#include <iostream>
#include <algorithm>
using namespace std;
int s[111], o[111];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d %d", &s[i], &o[i]);
	sort(s, s + m);
	sort(o, o + m);

	int ans = 0;
	if (n >= 6) {
		if (s[0] <= o[0] * 6) {
			ans += s[0] * (n / 6);
			n %= 6;
			if (s[0] <= o[0] * n) {
				if (n != 0) ans += s[0];
			}
			else {
				if (n != 0) ans += o[0] * n;
			}
		}
		else ans += o[0] * n;
	}
	else {
		if (s[0] < o[0] * n) ans += s[0];
		else ans += o[0] * n;
	}
	printf("%d\n", ans);
	return 0;
}