#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

set<string> s;

int main() {
	//ios::sync_with_stdio(false);

	int num;
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++) {
		string str1, str2;
		cin >> str1 >> str2;

		if (str2[0] == 'l') 
			s.erase(str1);
		
		else
			s.insert(str1);
	}
	

	for (set<string>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
		cout << *it << "\n";
	}
	return 0;
}