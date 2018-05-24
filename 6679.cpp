#include <iostream>
#include <algorithm>
using namespace std;

int go(int x, int mod) {
	int ret = 0;
	while (x != 0) {
		ret += x % mod;
		x /= mod;
	}
	return ret;
}

int main() {
	for (int i = 1000; i < 10000; i++) 
		if ((go(i, 10) == go(i, 12)) && (go(i, 12) == go(i, 16))) printf("%d\n", i);
	return 0;
}