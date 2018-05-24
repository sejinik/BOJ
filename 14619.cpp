#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define INF 987654321

int N, M;
int tcase;

int arr[110];
int dp[110][10010];

vector<vector<int>> vt;

int fun(int here, int count) {

	if (count == 0) return arr[here];

	int&ref = dp[here][count];
	if (ref != -1) return ref;

	ref = INF;
	for (int i = 0; i < vt[here].size(); i++) {
		int there = vt[here][i];
		ref = min(ref, fun(there, count - 1));
	}

	return ref;
}

int main() {
	memset(dp, -1, sizeof(dp));

	scanf("%d %d", &N, &M);
	vt.resize(N + 1);
	for (int i = 1; i <= N; i++) 
		scanf("%d", &arr[i]);
	
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		vt[u].push_back(v);
		vt[v].push_back(u);
	}

	scanf("%d", &tcase);

	while (tcase--) {
		int num, cnt;
		scanf("%d %d", &num,&cnt);

		if (fun(num, cnt) == INF)
			printf("-1\n");
		else
			printf("%d\n", fun(num, cnt));
	}
	return 0;
}