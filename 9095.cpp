#include <iostream>
using namespace std;

int d[12];

int main()
{
	int num;
	scanf("%d", &num);
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i <= 11; i++) 
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	
	while (num--) {
		int k;
		scanf("%d", &k);
		printf("%d\n", d[k]);
	}
	return 0;
}