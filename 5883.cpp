#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1111];
int main() {
	int n; scanf("%d", &n);
	vector<int> vt;
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp);
		arr[i] = temp;
		vt.push_back(temp);
	}
	sort(vt.begin(), vt.end());
	vt.erase(unique(vt.begin(), vt.end()),vt.end(	));

	for (int i = 0; i < vt.size(); i++) {
		for (int j = 0; j < n; j++) {
			if (vt[i] == arr[j]) arr[j] = i;
		}
		vt[i] = i;
	}

	int ans = 0;
	for (int i = 0; i < vt.size(); i++) {
		int temp = 0;
		int prev = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j] == vt[i]) continue;
			if (prev == arr[j]) temp += 1;
			else {
				ans = max(ans, temp);
				prev = arr[j];
				temp = 1;
			}
		}
		ans = max(ans, temp);
	}
	printf("%d\n", ans);
	return 0;
}