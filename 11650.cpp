#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>	
using namespace std;


int main() {
	int num;
	scanf("%d", &num);

	vector<pair<int, int>> vt(num);

	for (int i = 0; i < num; i++) {
		scanf("%d %d", &vt[i].first, &vt[i].second);
	}
	sort(vt.begin(), vt.end());
	for (int i = 0; i < num; i++) {
		printf("%d %d\n", vt[i].first, vt[i].second);
	}
	return 0;
}