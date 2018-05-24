#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vt;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		vt.push_back(temp);
	}
	sort(vt.begin(), vt.end());

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool check = binary_search(vt.begin(), vt.end(), m - vt[i]);
		if (check) cnt++;
	}
	printf("%d\n", cnt / 2);
	return 0;
}