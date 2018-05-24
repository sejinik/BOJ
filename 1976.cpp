#include <cstdio>

int n,m;
int p[202];

int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	p[x] = y;
}
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++)
		p[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int temp;
			scanf("%d", &temp);
			if (temp == 1)
				merge(i, j);
		}
	}
	for (int i = 1; i <= n; i++) 
		find(i);

	bool check = true;
	int temp;
	scanf("%d", &temp);
	temp = find(temp);
	for (int i = 0; i < m - 1; i++) {
		int a;
		scanf("%d", &a);
		if (temp != find(a)) {
			check = false;
			break;
		}
	}
	if (check)
		puts("YES");
	else
		puts("NO");
	return 0;
}