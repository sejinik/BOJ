#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define INF 1e+9
#define MAX 1000001
bool check[50050];
map<int,pair<int,int>> index_mp;
map<pair<int, int>, int> graph_mp;
int dx[24] = { -1,0,1,-1,1,-1,0,1 ,-2,0,2,-2,2,-2,0,2,1,2,-1,-2,1,2,-1,-2};
int dy[24] = { 1,1,1,0,0,-1,-1,-1 ,2,2,2,0,0,-2,-2,-2,2,1,2,1,-2,-1,-2,-1};

int main() {
	int n, T; scanf("%d %d", &n, &T);

	for (int i = 1; i <= n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		index_mp[i] = { a,b };
		graph_mp[{a, b}] = i;
	}


	int ans = INF;
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (int s = q.size()) {
		while (s--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (y == T) ans = min(ans, cnt);

			for (int i = 0; i < 24; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (0 <= nx && nx < MAX && 0 <= ny && ny <= T) {
					auto pos = graph_mp[{nx, ny}];
					if (pos != 0 && !check[pos]) {
						check[pos] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		cnt += 1;
	}

	if (ans == INF) puts("-1");
	else printf("%d\n", ans);
	return 0;
}