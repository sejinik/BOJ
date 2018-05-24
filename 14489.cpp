#include <cstdio>
#include <algorithm>
using namespace std;

int bank1, bank2;
int money;
int chicken;
int ans;

int main() {
	scanf("%d %d %d", &bank1, &bank2, &chicken);
	if (chicken == 0) {
		printf("%d\n", bank1 + bank2);
		return 0;
	}
	
	money = bank1 + bank2;
	int temp = money;
	while (money >= chicken) {
		ans += 1;
		money -= chicken;
	}
	
	if (ans >= 2)
		printf("%d\n", temp - chicken * 2);
	else
		printf("%d\n", temp);

	return 0;
}