#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int d[4444][4444];
int go(string&a, string&b, int x, int y) {
	if (x >= a.size() || y >= b.size()) return 0;
	int&ret = d[x][y];
	if (ret != -1) return ret;
	if (a[x] == b[y]) return ret = go(a, b, x + 1, y + 1) + 1;
	return 0;
}
int main() {
	memset(d, -1, sizeof(d));
	string A, B;
	cin >> A >> B;
	int ans = 0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j<B.size(); j++) {
			if(A[i] == B[j]) ans = max(ans, go(A, B, i, j));
		}
	}
	printf("%d\n", ans);
	return 0;
}