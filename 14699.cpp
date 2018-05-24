#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int d[5050];
int high[5050];
vector<vector<int>> vt;

int go(int here) {
	
	int &ret = d[here];
	if (d[here] != -1) return ret;

	int temp = 0;
	for (int i = 0; i < vt[here].size(); i++) {
		int next = vt[here][i];
		if (high[next] > high[here])
			temp = max(temp, go(next)+1);
	}

	return ret = temp;
}
int main() {
	memset(d, -1, sizeof(d));
	int n, m;
	scanf("%d %d ", &n, &m);
	vt.resize(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &high[i]);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) go(i);
	for (int i = 1; i <= n; i++) printf("%d\n", d[i] + 1);
	return 0;
}
