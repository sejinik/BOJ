#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
bool prime[10010];
int arr[4040][2];
int d[4040];
int prime_cnt;
int ax, ay, bx, by,n;
void make_prime() {
	for (int i = 2; i <= 10000; i++) {
		if (!prime[i]) {
			prime_cnt += 1;
			for (int j = i * 2; j <= 10000; j += i)
				prime[j] = true;
		}
	}
}
int dist(int a, int b, int c, int d) {
	return sqrt((c - a)*(c - a) + (d - b)*(d - b));
}
int main() {
	memset(d, -1, sizeof(d));
	prime[1] = true;
	make_prime();
	scanf("%d %d %d %d", &ax, &ay, &bx, &by);
	scanf("%d", &n);
	vector <vector<pair<int, int>>> graph(n + 3);
	arr[0][0] = ax; arr[0][1] = ay, arr[n + 1][0] = bx, arr[n + 1][1] = by;
	for (int i = 1; i <= n; i++) scanf("%d %d", &arr[i][0], &arr[i][1]);
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			int c = dist(arr[i][0], arr[i][1], arr[j][0], arr[j][1]);
			if (!prime[c]) {
				graph[i].push_back({ j,c });
				graph[j].push_back({ i,c });
			}
		}
	}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (d[here] != -1) continue;
		d[here] = cost;

		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int ncost = -graph[here][i].second - cost;
			if (d[next] == -1) pq.push({ ncost,next });
		}
	}
	printf("%d\n", d[n + 1]);
	return 0;
}