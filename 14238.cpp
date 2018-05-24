#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool d[55][55][55][3][3];
char ans[55];
int cnt[3];
int n;

bool go(int pos, int a, int b, int prev, int mprev) {
	if (pos == n) {
		if (a == cnt[0] && b == cnt[1]) {
			return true;
		}
		return false;
	}
	if (d[pos][a][b][prev][mprev]) return false;
	d[pos][a][b][prev][mprev] = true;

	ans[pos] = 'A';
	if (pos < 2) {
		if (go(pos + 1, a + 1, b, 0, mprev)) return true;
	}
	else {
		if (go(pos + 1, a + 1, b, 0, prev)) return true;
	}

	if (prev != 1) {
		ans[pos] = 'B';
		if (pos < 2) {
			if (go(pos + 1, a, b + 1, 1, mprev)) return true;
		}
		else {
			if (go(pos + 1, a, b + 1, 1, prev)) return true;
		}
	}
	if (prev != 2 && mprev != 2) {
		ans[pos] = 'C';
		if (pos < 2) {
			if (go(pos + 1, a, b, 2, mprev)) return true;
		}
		else {
			if (ans[pos - 1] == 'C' || ans[pos - 2] == 'C') return false;
			if (go(pos + 1, a, b, 2, prev)) return true;
		}
	}
	return false;
}

int main() {
	string s; cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) cnt[s[i] - 'A']++;
	if (go(0, 0, 0, 0,0)) cout << ans << endl;
	else puts("-1");
}