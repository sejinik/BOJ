#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<pair<int, int>>> vt;

char arr[1010];
int d[1010];
int n;

int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	vt.resize(n + 1);

	for (int i = 0; i < n; i++)
		scanf(" %1c", &arr[i]);

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == 'B') {
				if (arr[j] == 'O') {
					vt[i].push_back({ j,(j - i)*(j - i) });
				}
			}

			if (arr[i] == 'O') {
				if (arr[j] == 'J') {
					vt[i].push_back({ j,(j - i)*(j - i) });
				}
			}

			if (arr[i] == 'J') {
				if (arr[j] == 'B') {
					vt[i].push_back({ j,(j - i)*(j - i) });
				}
			}
		}
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,0 });
	
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (d[now] != -1)
			continue;
		d[now] = cost;

		for (int i = 0; i < vt[now].size(); i++) {
			int next = vt[now][i].first;
			int ncost = -vt[now][i].second - cost;

			if (d[next] != -1)
				continue;

			pq.push({ ncost, next });
		}
	}

	printf("%d\n", d[n-1]);
	return 0;
}