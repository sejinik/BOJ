#include <iostream>
#include <algorithm>
#include <vector>	
#include <utility>
using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	vector<pair<int, int>> vt(num);

	for (int i = 0; i < num; i++) {
		scanf("%d %d", &vt[i].second, &vt[i].first);
	}

	sort(vt.begin(), vt.end());
	for (int i = 0; i < num; i++) {
		printf("%d %d\n", vt[i].second, vt[i].first);
	}
	return 0;
}