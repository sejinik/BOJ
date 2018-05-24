#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string str;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		if (str[i] <= 'Z' && str[i] >= 'A') {
			if (str[i] + 13 > 'Z') {
				str[i] = (str[i] + 13) % ('Z') + 'A' - 1; 
			}
			else {
				str[i] = str[i] + 13;
			}
		}
		else if (str[i] <= 'z' && str[i] >= 'a') {
			if (str[i] + 13 > 'z') {
				str[i] = (str[i] + 13) % ('z') + 'a' -1;
			}
			else {
				str[i] = str[i] + 13;
			}
		}
	}
	cout << str << endl;
	return 0;

}