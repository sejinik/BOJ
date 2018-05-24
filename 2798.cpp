#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int arr[101];
int ans;

vector<int> vt;

void go(int index, int cnt) {

	if (cnt == 3) {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += vt[i];
		}
		if (sum > m) return;
		ans = max(ans, sum);
		return;
	}

	if (index == n) return;

	vt.push_back(arr[index]);
	go(index + 1, cnt + 1);

	vt.pop_back();
	go(index + 1, cnt);
}

int main() {
	scanf("%d %d", &n, &m);


	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	go(0, 0);
	printf("%d\n", ans);
	return 0;
}