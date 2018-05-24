#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;
string str[22];

char flip(char a) {
	if (a == 'H') return 'T';
	return 'H';
}
int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) cin >> str[i];

	int ans = 1e9;
	for (int state = 0; state < (1 << n); state++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				char pos = str[j][i];
				if (state&(1 << j)) {
					pos = flip(pos);
				}
				if (pos == 'T') cnt++;
			}
			sum += min(cnt, n - cnt);
		}
		ans = min(ans, sum);
	}
	printf("%d\n", ans);
}