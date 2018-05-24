#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, k;
bool check[361];

int main() {
	scanf("%d %d", &n, &k);
	vector<int> vt;
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp);
		vt.push_back(temp);
		check[temp] = true;
		for (int j = temp; j <= 360; j += temp) {
			vt.push_back(j);
			check[j] = true;
		}
	}

	while (true) {
		int cnt1 = 0;
		for (int i = 0; i <= 360; i++)
			if (check[i]) cnt1 += 1;

		int m = vt.size();
		for (int i = 0; i < m-1; i++) {
			for (int j = i + 1; j < m; j++) {
				int temp = vt[i] + vt[j];
				temp %= 360;
				check[temp] = true;
				vt.push_back(temp);

				temp = abs(vt[i] - vt[j]);
				temp %= 360;
				check[temp] = true;
				vt.push_back(temp);
			}
		}

		sort(vt.begin(), vt.end());
		vt.erase(unique(vt.begin(), vt.end()), vt.end());

		int cnt2 = 0;
		for (int i = 0; i <= 360; i++)
			if (check[i]) cnt2 += 1;

		if (cnt1 == cnt2) break;
	}

	for (int i = 0; i < k; i++) {
		int temp; scanf("%d", &temp);
		if (check[temp]) puts("YES");
		else puts("NO");
	}

	return 0;
}