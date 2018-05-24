#include <iostream>
#include <string>
using namespace std;
bool check[111][111];
int main() {
	string str;
	cin >> str;
	int l = str.size();
	for (int i = 0; i < l; i++) check[i][i] = true;
	for (int i = 0; i < l-1; i++) 
		if (str[i] == str[i + 1]) check[i][i + 1] = true;
	
	for (int k = 2; k < l; k++) {
		for (int i = 0; i < l - k; i++) {
			int j = i + k;
			if (str[i] == str[j] && check[i + 1][j - 1]) check[i][j] = true;
		}
	}
	printf("%d\n", check[0][l - 1]);
	return 0;
}