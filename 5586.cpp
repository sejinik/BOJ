#include<iostream>
#include <string>
using namespace std;
int joi, ioi;

int main() {
	string str;
	cin >> str;
	int l = str.size();
	for (int i = 0; i < l - 2; i++) {
		if (str[i] == 'J') 
			if (str[i + 1] == 'O' && str[i + 2] == 'I') joi += 1;
		
		if (str[i] == 'I')
			if (str[i + 1] == 'O' && str[i + 2] == 'I') ioi += 1;
	}
	printf("%d\n", joi);
	printf("%d\n", ioi);
	return 0;
}