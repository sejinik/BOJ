#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
double d[(1 << 21)];
bool check[(1 << 21)];
double map[22][22];
int n;

double go(int pos,int visited) {
	if (pos == n) return 1.0;
	double&ret = d[visited];
	if (check[visited]) return ret;
	check[visited] = true;
	ret = 0.0;
	for (int i = 0; i < n; i++) {
		if (!(visited&(1 << i))) ret = max(ret, go(pos + 1, (visited | (1 << i)))*map[pos][i]);
	}
	return ret;
}
int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x; scanf(" %d", &x);
			map[i][j] = (double)x/100.0;
		}
	}

	printf("%lf\n", go(0, 0) * 100.0);
}