#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
	scanf("%d %d", &n, &m);
	vector<int> vt;
	for (int i = 0; i < n + m; i++) {
		int num;
		scanf("%d", &num);
		vt.push_back(num);
	}
	sort(vt.begin(), vt.end());
	
	for (vector<int>::iterator it = vt.begin(); it != vt.end(); ++it) {
		printf("%d ", *it);
	}
	printf("\n");
	return 0;
}