#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> vt;
int n;
int arr[11][11];
int ans=987654321;


int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		vt.push_back(i);
	}

	do {
		bool ok = true;
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			if (!arr[vt[i]][vt[i + 1]])
				ok = false;
			else
				sum += arr[vt[i]][vt[i + 1]];
		}

		if (ok && arr[vt[n - 1]][vt[0]] != 0) {
			sum += arr[vt[n - 1]][vt[0]];
			ans = min(ans, sum);
		}
	} while (next_permutation(vt.begin(), vt.end()));

	printf("%d\n", ans);
	return 0;
}