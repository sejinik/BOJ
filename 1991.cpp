#include <iostream>
#include <cstring>
using namespace std;
int arr[27][2];
bool check[26];
int n;

void dfs(int x) {
	check[x] = true;
	printf("%c", x + 'A');
	if (arr[x][0] != -1 && !check[arr[x][0]]) dfs(arr[x][0]);
	if (arr[x][1] != -1 && !check[arr[x][1]]) dfs(arr[x][1]);
}

void dfs1(int x) {
	check[x] = true;
	if (arr[x][0] != -1 && !check[arr[x][0]]) dfs1(arr[x][0]);
	printf("%c", x + 'A');
	if (arr[x][1] != -1 && !check[arr[x][1]]) dfs1(arr[x][1]);
}
void dfs2(int x) {
	check[x] = true;
	if (arr[x][0] != -1 && !check[arr[x][0]]) dfs2(arr[x][0]);
	if (arr[x][1] != -1 && !check[arr[x][1]]) dfs2(arr[x][1]);
	printf("%c", x + 'A');
}
int main() {
	memset(arr, -1, sizeof(arr));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char a, b, c; scanf(" %c %c %c", &a, &b, &c);
		if (b != '.') arr[a - 'A'][0] = b - 'A';
		if (c != '.') arr[a - 'A'][1] = c - 'A';
	}
	dfs(0); puts("");
	memset(check, 0, sizeof(check));
	dfs1(0); puts("");
	memset(check, 0, sizeof(check));
	dfs2(0); puts("");
}