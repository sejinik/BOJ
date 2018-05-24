#include <iostream>
using namespace std;

long long d[101] = { 0,1,1,1,2,2,3,4,5,7,9 };

int main()
{
	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {

	long long num;
	scanf("%lld", &num);
	for (int i = 11; i <= num; i++) {
		d[i] = d[i - 1] + d[i - 5];
	}
	printf("%lld\n", d[num]);
	}
	return 0;
}