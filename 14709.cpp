#include <iostream>
using namespace std;
int p[10];
bool check[10][10];

int Find(int x) {
	if (x == p[x]) return x;
	else return p[x] = Find(p[x]);
}

void merge(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	p[y] = x;
}

int main() {
	for (int i = 1; i <= 5; i++) p[i] = i;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
		check[a][b] = true;
	}
	bool go = true;
	if ((check[1][3] || check[3][1]) && (check[3][4] || check[4][3]) && (check[1][4] || check[4][1])) go = true;
	else go = false;
	for (int i = 1; i <= 5; i++) Find(i);
	if (Find(1) == Find(3) && Find(3) == Find(4) && Find(1) != Find(2) && Find(4) != Find(5) && go)
		puts("Wa-pa-pa-pa-pa-pa-pow!");
	else
		puts("Woof-meow-tweet-squeek");
	return 0;
}