#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, x;
vector<int> vt;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		vt.push_back(temp);
	}

	sort(vt.begin(), vt.end());
	scanf("%d", &x);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool check = binary_search(vt.begin(), vt.end(), x - vt[i]);
		if (check)
			cnt++;
	}
	printf("%d\n", cnt/2);
	return 0;
}