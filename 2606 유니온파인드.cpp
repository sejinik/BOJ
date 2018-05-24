#include <cstdio>

int n, m;
int p[101];

int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return;
	p[y] = x;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
		p[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		merge(a, b);
	}

	
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (find(1) == find(i))
			cnt += 1;
	}

	printf("%d\n", cnt);
	return 0;
}