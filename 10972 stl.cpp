#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	int n;
	scanf("%d", &n);

	vector<int> vt;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		vt.push_back(num);
	}

	if (next_permutation(vt.begin(), vt.end())) {
		for (int i = 0; i < vt.size(); i++) {
			printf("%d ", vt[i]);
		}
		printf("\n");
	}
	else {
		printf("-1\n");
	}
	return 0;
}