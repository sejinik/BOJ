#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[101];
double color[3];
double money;
int n;

int main() {
	scanf("%lf %d", &money, &n);
	money = double(money / 100);

	while (n--) {
		int num;
		char a;
		scanf("%d %c", &num, &a);
		if (a == 'R') {
			for (int i = num + 1; i <= 100; i++) {
				arr[i] += 1;
				arr[i] %= 3;
			}
		}
		else {
			for (int i = num-1; i > 0; i--) {
				arr[i] += 1;
				arr[i] %= 3;
			}
		}
	}
	for (int i = 1; i <= 100; i++)
		color[arr[i]]++;

	for (int i = 0; i < 3; i++)	{
		color[i] = money * color[i];
		printf("%.2lf\n", color[i]);
	}
	return 0;

}