#include <iostream>
#include <algorithm>
using namespace std;

int d[100001], a[100001];

int main()
{
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		int sco;
		scanf("%d", &sco);
		a[i] = sco;
		d[i] = a[i];
	}

	for (int i = 2; i <= num; i++) {
			d[i] = max(d[i], d[i - 1] + a[i]);
	}

	int ans = -1000;
	for (int i = 1; i <= num; i++)
		ans = max(ans, d[i]);

	printf("%d\n", ans);
	return 0;
}