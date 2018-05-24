#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int cnt;

int main() {
	int num;
	scanf("%d", &num);

	vector< pair<int, int>> vt;
	vt.resize(num + 1);

	for (int i = 1; i <= num; i++) {
		scanf("%d %d", &vt[i].first, &vt[i].second);
	}

	for (int i = 1; i <= num; i++) {
		cnt = 0;
		for (int j = 1; j <= num; j++) {
			if (i == j) continue;
			if (vt[i].first < vt[j].first && vt[i].second < vt[j].second) {
				cnt++;
			}
		}
		printf("%d ", cnt+1);
	}
	return 0;
}