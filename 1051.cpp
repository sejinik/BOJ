#include <iostream>
#include <algorithm>
using namespace std;

int ans;
int arr[51][51];
int N, M;

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}


	int ans = 1;
	int size = min(N, M);
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < M-1; j++) {
			for (int k = 1; k < size; k++) {
				if ((arr[i][j] == arr[i][j + k]) && (arr[i][j] == arr[i + k][j]) && (arr[i][j] == arr[i + k][j + k])) {
					if ((i + k >= N) || (j + k >= M)) continue;

					int temp = (k + 1)*(k + 1);
					ans = max(ans, temp);
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
