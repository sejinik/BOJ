#include <iostream>
#include <algorithm>
using namespace std;

int d[1001];
int a[1001];

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		int sco;
		scanf("%d", &sco);
		a[i] = sco;
	}

	d[1] = a[1];
	
	for(int i = 2; i <= num; i++)
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i])
				d[i] = max(d[i], d[j] + a[i]);
			else
				d[i] = max(d[i], a[i]);
		}
		
	int ans = 0;
	for (int i = 1; i <= num; i++) {
		ans = max(ans, d[i]);
	}
	
	printf("%d\n", ans);
	return 0;
}