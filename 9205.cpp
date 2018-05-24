#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int>> vt2;

bool check[105];
int tcase;
int a[105][105];

void dfs(int here) {
	check[here] = true;

	for (int i = 0; i < vt2[here].size(); i++) {
		int there = vt2[here][i];
		if (!check[there])
			dfs(there);
	}
}

int main() {
	scanf("%d", &tcase);

	while (tcase--) {
		memset(check, 0, sizeof(check));
		memset(a, 0, sizeof(a));
		int n;
		
		scanf("%d", &n);
		vector<pair<int, int>> vt;
		vt2.resize(n + 2);
		for (int i = 0; i < n + 2; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			vt.push_back({ u,v });
		}

		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < n + 2; j++) {
				if (i == j) continue;
				if (abs(vt[i].first - vt[j].first) + abs(vt[i].second - vt[j].second) <= 1000)
					a[i][j] = 1;
			}
		}
		for (int i = 0; i < n + 2; i++) {
			a[i][i] = 0;
		}
			
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < n + 2; j++) {
				for (int k = 0; k < n + 2; k++) {
					if (j == k) continue;
					if (a[j][k] == 0)
						a[j][k] = a[j][i] & a[i][k];
				}
			}
		}

		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < n + 2; j++) {
				if (i == j) continue;
				if (a[i][j] == 1)
					vt2[i].push_back(j);
			}
		}

		dfs(0);

		if (check[n + 1])
			puts("happy");
		else
			puts("sad");

		vt2.clear();
	}
}