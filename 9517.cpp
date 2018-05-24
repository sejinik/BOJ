#include <iostream>
using namespace std;
int k, n;

int main() {
	int time = 210;
	scanf("%d %d", &k, &n);
	for (int i = 0; i < n; i++) {
		int temp;
		char c;	
		cin >> temp >> c;
		time -= temp;

		if (time < 0) {
			printf("%d\n", k);
			return 0;
		}
		else {
			if (c == 'T') {
				k += 1;
				if (k > 8) 
					k %= 8;
			}
		}
	}
	return 0;
}