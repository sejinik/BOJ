#include <cstdio>
#include <vector>
using namespace std;

int n,m,start;
int parent[55];
int tin[55];
int tout[55];
int timer;
vector<vector<int>> a;

void init(int x) {
	tin[x] = timer++;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (y != parent[x]) {
			init(y);
		}
	}
	tout[x] = timer++;
}

void init2(int x) {
	if (x == m) return;
	tin[x] = timer++;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (y != parent[x]) {
			init2(y);
		}
	}
	tout[x] = timer++;
}

void remove(int x) {
	tin[x] = 0;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (y != parent[x]) 
			remove(y);
	}
	tout[x] = 0;
}

int main() {
	scanf("%d", &n);
	a.resize(n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == -1) {
			start = i;
			parent[i] = -1;
			continue;
		}
		a[i].push_back(x);
		a[x].push_back(i);
		parent[i] = x;
	}
	init(start);
	scanf("%d", &m);
	remove(m);
	timer = 0;
	init2(start);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (tout[i] - tin[i] == 1) {
			cnt += 1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}