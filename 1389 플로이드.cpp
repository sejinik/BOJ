#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[105][105];
int ans[105];

int N, M;

int main() {
	scanf("%d%d", &N, &M);
	memset(a, 0x3f, sizeof(a));

	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		a[u][v] = a[v][u] = 1;
	}
	for (int i = 1; i <= N; i++)
		a[i][i] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				//if(a[j][i] + a[i][k] != 0)
					a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
			}
		}
	}

	int s_ans = 987654321;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans[i] += a[i][j];
		}
		s_ans = min(s_ans, ans[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (s_ans == ans[i]) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}