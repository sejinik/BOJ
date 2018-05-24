#include <iostream>
#include <cstring>
using namespace std;

bool check[101];
int dp[101];
int cnt;

int main() {


	for (int i = 5; i <= 100; i++) {
		memset(check, 0, sizeof(check));

		for (int j = 1; j <= i; j++) {
			for (int k = j; k <= i; k = k + j) {
				if (check[k] == true)
					check[k] = false;
				else
					check[k] = true;
			}
		}
		cnt = 0;
		for (int z = 1; z <= i; z++) {
			if (check[z] == true)
				cnt++;
		}
		dp[i] = cnt;
	}

	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int num;
		scanf("%d", &num);

		printf("%d\n", dp[num]);
	}
	return 0;
}