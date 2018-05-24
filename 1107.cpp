#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// ¸Á°¡Áö¸é true
bool button[10];
int channel;
int M;

int ans, res, num;

int possible(int c) {
	if (c == 0) {
		if (button[0] == true)
			return 0;

			return 1;
	}

	int cnt = 0;
	while (c > 0) {
		if (button[c % 10])
			return 0;
		cnt++;
		c /= 10;
	}

	return cnt;
}
int main() {
	scanf("%d", &channel);
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		button[temp] = true;
	}

	ans = abs(100 - channel);
	for (int i = 0; i <= 1000000; i++) {
		if (possible(i) == 0)
			continue;

		num = possible(i) + abs(i - channel);
		
		ans = min(ans, num);
	}

	printf("%d\n", ans);
}