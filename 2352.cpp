#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> vt;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);

		auto pos = lower_bound(vt.begin(), vt.end(), temp);
		if (pos == vt.end()) vt.push_back(temp);
		else *pos = temp;
	}
	printf("%d\n", vt.size());
	return 0;
}