#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, k;

long long sum(vector<long long>& tree, int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i& -i);
	}
	return ans;
}

void update(vector<long long>&tree, int i, int value) {
	while (i < tree.size()) {
		tree[i] += value;
		i += (i&-i);
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	vector<long long> a(n + 1);
	vector<long long>tree(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		update(tree, i, a[i]);
	}

	for (int i = 0; i < m + k; i++) {
		int x, y;
		long long z;
		scanf("%d %d %lld", &x, &y, &z);
		if (x == 1) {
			long long temp = z - a[y];
			update(tree, y, temp);
			a[y] = z;
		}
		else {
			printf("%lld\n", sum(tree,z) - sum(tree,y - 1));
		}
	}
	return 0;
}