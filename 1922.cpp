#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define INF 987654321
int n, m;
bool check[1010];
int ans;

int main() {
	scanf("%d %d", &n, &m);

	vector < vector<pair<int, int>>> vt(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vt[u].push_back({ v,w }); 
		vt[v].push_back({ u,w });
	}

	priority_queue<pair<int, int>> pq;
	

	pq.push({ 0,1 });
	while (!pq.empty()) {
		int x = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (!check[x]) {
			check[x] = true;
			ans += cost;
			for (int i = 0; i < vt[x].size(); i++) {
				int nx = vt[x][i].first;
				int ncost = vt[x][i].second;

				if(!check[nx])
				pq.push({ -ncost,nx });
			}
		}	
	}


	printf("%d\n", ans);
	return 0;
}