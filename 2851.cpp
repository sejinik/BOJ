#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<pair<int, int>> vt(10);

int main() {
	
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		int temp;
		scanf("%d", &temp);
		sum += temp;
		vt[i].second = sum;
		vt[i].first = abs(100 - sum);
	}

	sort(vt.begin(), vt.end());
	int ans = 0;
	if (vt[0].first == vt[1].first)
		ans = max(vt[0].second, vt[1].second);
	else
		ans = vt[0].second;

	printf("%d\n", ans);
	return 0;
}