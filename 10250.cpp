#include <iostream>
using namespace std;

int x, y;
int main() {
	int Tcase;
	scanf("%d", &Tcase);

	while (Tcase--) {
		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);

		for (int i = 1; i <= W; i++) {
			for (int j = 1; j <= H; j++) {
				N--;
				if (N == 0) {
					x = i;
					y = j;
					break;
				}
			}
			if (N == 0)
				break;
		}
		cout << y;
		if (x < 10)
			cout << "0" << x << endl;
		else
			cout << x << endl;
	}
	return 0;
}