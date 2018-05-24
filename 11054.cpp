#include <iostream>
#include <algorithm>
using namespace std;

int arr[1010];
int dp[1010];
int dp2[1010];

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= num; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j]+ 1)
				dp[i] = dp[j] + 1;
		}
	}

	reverse(arr+1, arr + num+1);
	for (int i = 1; i <= num; i++) {
		dp2[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && dp2[i] < dp2[j] + 1)
				dp2[i] = dp2[j] + 1;
		}
	}

	reverse(dp2+1, dp2 + num+1);
	int ans = 0;
	for (int i = 1; i <= num; i++) {
		if (i == num)
			ans = max(ans, dp[i]);
		else if (i == 1)
			ans = max(ans, dp2[i]);
		else
			ans = max(ans, dp[i] + dp2[i]-1);
	}
	printf("%d\n", ans);
	return 0;
}