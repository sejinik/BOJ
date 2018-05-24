#include <iostream>
#include <algorithm>
using namespace std;

int d[301], a[301];

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

	d[2] = a[1] + a[2];
	for (int i = 3; i <= num; i++) {
		d[i] = max(d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]);
	}

	int ans = d[num];
	printf("%d\n", ans);
	return 0;
}