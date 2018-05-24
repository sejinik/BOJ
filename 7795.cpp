#include <iostream>
#include <algorithm>
using namespace std;

int tcase, n, m;

int nArr[20010];
int mArr[20010];

int main() {
	scanf("%d", &tcase);

	while (tcase--) {
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++)
			scanf("%d", &nArr[i]);

		for (int i = 0; i < m; i++)
			scanf("%d", &mArr[i]);

		sort(nArr, nArr + n);
		sort(mArr, mArr + m);

		int sum = 0;
		for (int i = 0; i < n; i++) {
			int num = upper_bound(mArr, mArr + m, nArr[i]) - mArr;
			while (nArr[i] == mArr[num - 1]) {
				num--;
			}
			

			sum += num;
		}
		printf("%d\n", sum);

	}
	return 0;
}