#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
char arr[222][222];
int n, m;

void one() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][m*2-1 - j] = arr[i][j];
		}
	}
}
void two() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[n*2-1 - i][j] = arr[i][j];
		}
	}
}
void three() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[n*2-1 - i][m*2-1 - j] = arr[i][j];
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf(" %s", &arr[i]);
	}
	int x, y;
	scanf("%d %d", &x, &y);
	one();
	two();
	three();
	
	if (arr[x - 1][y - 1] == '#') arr[x - 1][y - 1] = '.';
	else arr[x - 1][y - 1] = '#';
	for (int i = 0; i < n * 2; i++) {
		for (int j = 0; j < m * 2; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}