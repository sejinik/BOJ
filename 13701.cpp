#include <iostream>
#include <bitset>
using namespace std;

bitset<(1 << 24)> bt;
int s;

int main() {
	int num;
	
	while (scanf("%d",&num) != EOF) {
		if (!bt[num]) {
			bt[num] = 1;
			printf("%d ", num);
		}
	}
	return 0;
}