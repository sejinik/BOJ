#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int arr[101][3];
int A[101];
int B[101];
int C[101];

int main() {
	scanf("%d %d ", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
		A[i] = arr[i][0];
		B[i] = arr[i][1];
		C[i] = arr[i][2];
	}
	int ans = 1000000000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int q = 0; q < n; q++) {
				int cnt = 0;
				for (int o = 0; o < n; o++) {
					if (A[i] >= arr[o][0] && B[j] >= arr[o][1] && C[q] >= arr[o][2]) {
						cnt += 1;
						if (cnt >= k) {
							ans = min(ans, A[i] + B[j] + C[q]);
						}
					}	
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}