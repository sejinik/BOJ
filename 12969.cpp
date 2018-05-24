#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
bool d[33][33][33][555];
char ans[33];

bool go(int i, int a, int b, int p) {
	if (i == n) {
		if (k == p) return true;
		return false;
	}
	if (d[i][a][b][p]) return false;
	d[i][a][b][p] = true;
	ans[i] = 'A';
	if (go(i + 1, a + 1, b, p)) return true;

	ans[i] = 'B';
	if (go(i + 1, a, b + 1, p + a)) return true;

	ans[i] = 'C';
	if (go(i + 1, a, b, p + a + b)) return true;

	return false;
}
int main() {
	scanf(" %d %d", &n, &k);
	if (go(0, 0, 0, 0)) cout << ans << endl;
	else cout << -1 << endl;
}