#include <iostream>
#include <string>
using namespace std;

int small_go(string& str1, string& str2) {
	int l1 = str1.size();
	int l2 = str2.size();
	for (int i = 0; i < l1; i++) 
		if (str1[i] == '6') str1[i] = '5';
	
	for (int i = 0; i < l2; i++)
		if (str2[i] == '6') str2[i] = '5';

	int n1 = stoi(str1);
	int n2 = stoi(str2);
	return n1 + n2;
}
int big_go(string& str1, string& str2) {
	int l1 = str1.size();
	int l2 = str2.size();
	for (int i = 0; i < l1; i++)
		if (str1[i] == '5') str1[i] = '6';

	for (int i = 0; i < l2; i++)
		if (str2[i] == '5') str2[i] = '6';

	int n1 = stoi(str1);
	int n2 = stoi(str2);
	return n1 + n2;
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	printf("%d %d\n", small_go(str1, str2), big_go(str1, str2));
	return 0;
}