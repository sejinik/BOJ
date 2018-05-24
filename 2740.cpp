#include <iostream>
#include <algorithm>
using namespace std;
int arr1[111][111];
int arr2[111][111];
int ans[111][111];
int n, m,x,y;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr1[i][j]);
		}
	}
	
	scanf("%d %d", &x, &y);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			scanf("%d", &arr2[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < m; k++) {
				ans[i][j] += (arr1[i][k] * arr2[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < y; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}