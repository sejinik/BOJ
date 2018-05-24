#include <iostream>
#include <string>
using namespace std;

int n;
string pa;

int main() {
	scanf("%d", &n);
	cin >> pa;
	string pa1, pa2;
	int pos = pa.find('*');
	for (int i = 0; i < pos; i++) pa1 += pa[i];
	for (int i = pos+1; i < pa.size(); i++) pa2 += pa[i];

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		if (temp.size() < pa1.size() + pa2.size()) {
			puts("NE");
			continue;
		}
		bool check = true;
		for (int j = 0; j < pa1.size(); j++) {
			if (pa1[j] != temp[j]) {
				check = false;
				break;
			}
		}
		if (!check) puts("NE");	
		else {
			int size = temp.size() - pa2.size();
			for (int j = 0; j < pa2.size(); j++) {
				if (pa2[j] != temp[size++]) {
					check = false;
					break;
				}
			}
			if (check) puts("DA");
			else puts("NE");
		}
	}
	return 0;
}