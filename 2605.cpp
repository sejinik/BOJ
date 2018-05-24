#include <cstdio>
#include <vector>
#include <algorithm>	
using namespace std;

int n;
vector<int> vt;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		vt.push_back(i + 1);

		int temp;
		scanf("%d", &temp);
		if (i == 0) continue;

		int pos = i;
		while (temp--) {
			swap(vt[pos - 1], vt[pos]);
			pos -= 1;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", vt[i]);
	printf("\n");
	return 0;
}