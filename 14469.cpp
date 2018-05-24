#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	scanf("%d ", &n);
	vector<pair<int, int>> vt(n);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt[i].first = a;
		vt[i].second = b;
	}
	sort(vt.begin(), vt.end());
	int time = 0;
	for (int i = 0; i < n; i++) {
		if (time < vt[i].first) 
			time = vt[i].first;

			time += vt[i].second;
		
	}
	printf("%d\n", time);
	return 0;
}