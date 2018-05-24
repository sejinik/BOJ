#include <iostream>
#include <string>
using namespace std;

int tcase;
string str1, str2;

int main() {
	scanf("%d", &tcase);

	while (tcase--) {
		cin >> str1 >> str2;
		cout << "Distances: ";
		for (int i = 0; i < str1.size(); i++) {
			int x, y,ans;
			x = str1[i] - 'A';
			y = str2[i] - 'A';

			if (y >= x)
				ans = y - x;
			else
				ans = (y + 26) - x;
			cout << ans<<" ";
		}
		printf("\n");
	}
	return 0;
}