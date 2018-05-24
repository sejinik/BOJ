#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[1010][1010];
void Euler(int x, vector<int> &ans) {
	for (int i = 0; i < n; i++) {
		while (arr[x][i] > 0) {
			arr[x][i]--;
			arr[i][x]--;
			Euler(i, ans);
		}
	}
	ans.push_back(x+1);
}
int main() {
	scanf("%d", &n);
	vector<int> ans;
	bool check_start = true;
	bool zero = false;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j]) zero = true;
			sum += arr[i][j];
		}
		if (sum % 2 == 1) check_start = false;
	}

	if (check_start && zero) {
		Euler(0, ans);
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	else puts("-1");
	return 0;
}