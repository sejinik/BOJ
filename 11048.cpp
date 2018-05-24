#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1010][1010];
int arr[1010][1010];


int main() {
	
	memset(arr, -1, sizeof(arr));

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1;j <= M; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i == 1 && j == 1) continue;

			dp[i][j] = max(max(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + arr[i][j];
		}
	}

	printf("%d\n", dp[N][M]);
	return 0;
}