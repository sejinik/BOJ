#include <iostream>
#include <string>
using namespace std;


int main() {
	
	int ans = 0;

	for (int i = 0; i < 8; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (str[j] == 'F' && j % 2 == 0)
					ans++;
			}
			else {
				if (str[j] == 'F' && j % 2 != 0)
					ans++;
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}