#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

int arr[500010];
int n, m;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);

		pair<int*, int*> p;

		p = equal_range(arr, arr + n, num);
		printf("%d ", p.second - p.first);
	}
	printf("\n");
	return 0;
}