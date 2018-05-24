#include <cstdio>
#include <algorithm>
using namespace std;

int arr[500010];
int n, m;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr + n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);

		int left = 0;
		int right = n - 1;

		bool check = false;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] == x) {
				check = true;
				break;
			}
			else if (arr[mid] > x)
				right = mid - 1;
			else
				left = mid + 1;
		}
		
		if (check)
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
	return 0;
}