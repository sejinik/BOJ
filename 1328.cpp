#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define ll long long 
int n, l, r;
ll d[111][111][111];

int main() {
	scanf("%d %d %d", &n, &l, &r);
	d[1][1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				d[i + 1][j + 1][k] += d[i][j][k];
				d[i + 1][j + 1][k] %= MOD;
				
				d[i + 1][j][k + 1] += d[i][j][k];
				d[i + 1][j][k + 1] %= MOD;

				d[i + 1][j][k] += d[i][j][k] * (i - 1);
				d[i + 1][j][k] %= MOD;
			}
		}
	}
	printf("%lld\n", d[n][l][r]);
}