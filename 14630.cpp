#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int n,from, to;
int dist[1010];
string arr[1010];
int cost(string&str1, string&str2) {
	int ret = 0;
	int l = str1.size();
	for (int i = 0; i < l; i++) {
		int a = str1[i] - '0';
		int b = str2[i] - '0';
		ret += (a - b)*(a - b);
	}
	return ret;
}

int main() {
	memset(dist, -1, sizeof(dist));
	scanf("%d", &n);
	vector<vector<pair<int, int>>> vt(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	scanf("%d %d", &from, &to);
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n; j++) {
			int w = cost(arr[i], arr[j]);
			vt[i].push_back({ j,w });
			vt[j].push_back({ i,w });
		}
	}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,from-1 });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[here] != -1) continue;
		dist[here] = cost;

		for (int i = 0; i < vt[here].size(); i++) {
			int next = vt[here][i].first;
			int ncost = -cost - vt[here][i].second;
			if (dist[next] != -1) continue;
			pq.push({ ncost,next });
		}
	}
	printf("%d\n", dist[to-1]);
	return 0;
}