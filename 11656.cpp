#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[1000];

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		s[i] = str.substr(i, str.length());
	}
	
	sort(s,s+str.length()); 
	
	for (int i = 0; i < str.length(); i++) {
		cout << s[i] << endl;
	}
	return 0;
}