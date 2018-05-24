#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<pair<int, int>> vt(10);
	for (int i = 0; i < 9; i++) {
		int n; scanf(" %d", &n);
		vt[i].first = n;
		vt[i].second = i+1;
	}
	sort(vt.begin(), vt.end());
	reverse(vt.begin(), vt.end());
	printf("%d\n", vt[0].first);
	printf("%d\n", vt[0].second);
	return 0;
}