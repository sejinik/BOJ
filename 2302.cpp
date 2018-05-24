#include <iostream>
#include <algorithm>
using namespace std;
bool arr[55];
int d[55];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int seat; scanf("%d", &seat);
		arr[seat] = true;
	}
	d[1] = 1; 
	if(!arr[1] && !arr[2]) d[2] = 2;
	else d[2] = 1; 
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1];
		if (arr[i - 1]) d[i] - d[i - 1];
		else if(!arr[i]) d[i] = d[i - 1] + d[i - 2];
	}
	printf("%d\n", d[n]);
	return 0;
}