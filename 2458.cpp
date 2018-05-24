#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int a[505][505];
bool check[505];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u][v] = 1;
	}
	for (int i = 1; i <= n; i++)
		a[i][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k) continue;
				if(a[j][k] == 0)
				a[j][k] = a[j][i] & a[i][k];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		bool can = true;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (a[i][j] == 0 && a[j][i] == 0)
				can = false;
		}
		if (can)
			check[i] = true;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (check[i])
			cnt++;

	printf("%d\n", cnt);
	return 0;

}