#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> vt;

	for (int i = 0; i < n; i++) {
		vt.push_back(i + 1);
	}

	do {
		for (int i = 0; i < vt.size(); i++) {
			printf("%d ", vt[i]);
		}
		printf("\n");
	} while (next_permutation(vt.begin(), vt.end()));

	return 0;
}