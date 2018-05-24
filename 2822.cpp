#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vt(8);
vector<int> num(5);
int sum;

int main() {
	for (int i = 0; i < 8; i++) {
		scanf("%d", &vt[i].first);
		vt[i].second = i + 1;
	}
	sort(vt.begin(), vt.end());
	reverse(vt.begin(), vt.end());
	for (int i = 0; i < 5; i++) {
		sum += vt[i].first;
		num[i] = vt[i].second;
	}
	sort(num.begin(), num.end());
	printf("%d\n", sum);
	for (int i = 0; i < 5; i ++ ) {
		printf("%d ", num[i]);
	}
	return 0;
}