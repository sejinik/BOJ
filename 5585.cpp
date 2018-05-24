#include <iostream>
using namespace std;

int main() {
	int num;
	scanf("%d", &num);

	int money = 1000 - num;
	int ans = 0;

	while (money != 0) {


		if (money >=500) {
			ans += money / 500;
			money %= 500;
		}

		else if (money >= 100) {
			ans += money / 100;
			money %= 100;
		}
		
		else if (money >= 50) {
			ans += money / 50;
			money %= 50;
		}
		else if (money >=10) {
			ans += money / 10;
			money %= 10;
		}
		else if (money >= 5) {
			ans += money / 5;
			money %= 5;
		}
		else {
			ans += money / 1;
			money %= 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}