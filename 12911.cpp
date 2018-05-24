#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define mod 1000000007
ll d[11][100010];
ll sum[11];
vector<int> vt[100010];
int n, k;

int main() {
	scanf(" %d %d", &n, &k);
	for (int i = 1; i <= k; i++) d[1][i] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = i * 2; j <= k; j += i) {
			vt[j].push_back(i);
		}
	}

	sum[1] = k;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			d[i][j] += sum[i - 1];
			for (int q = 0; q < vt[j].size(); q++) {
				d[i][j] -= d[i - 1][vt[j][q]];
				d[i][j] %= mod;
				d[i][j] += mod;
				d[i][j] %= mod;
			}
			sum[i] += d[i][j];
			sum[i] %= mod;
		}
	}
	printf("%lld\n", sum[n]);
}