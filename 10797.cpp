#include <iostream>
#include <string>
using namespace std;

int cnt;

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < 5; i++) {
		string str2;
		cin >> str2;
		
		if (str2 == str)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}