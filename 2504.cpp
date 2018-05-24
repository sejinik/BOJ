#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
int check[33];
int point[33];
int i, j;

int main() {
	cin >> s;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(' || s[i] == '[') check[j++] = (s[i] == '(') ? ')' : ']';
		if (s[i] == ')' || s[i] == ']') {
			j--;
			if (j < 0 || check[j] != s[i]) {
				point[0] = 0; break;
			}
			point[j] += (check[j] == ')' ? 2 : 3)*(point[j + 1] ? point[j + 1] : 1);
			point[j + 1] = 0;
		}
	}
	printf("%d\n", point[0]);
}