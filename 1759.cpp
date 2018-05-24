#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;
char alpha[20];
string str;
int cnt;

vector<char> vt;

bool check(vector<char> &a) {
	int mo = 0;
	int ja = 0;
	for (int i = 0; i < L; i++) {
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
			mo++;
		else
			ja++;
	}

	if (mo >= 1 && ja >= 2)
		return true;

	return false;
}
void go(int len, int index) {

	if (len == L) {
		bool print = check(vt);

		if (print) {
			for (int i = 0; i < vt.size(); i++) {
				printf("%c", vt[i]);
			}
			printf("\n");
		}
		return;
	}

	if (index == C) return;

	vt.push_back(alpha[index]);
	go(len + 1, index + 1);
	vt.pop_back();

	go(len, index + 1);
}

int main() {
	char bu;
	scanf("%d%d", &L, &C);
	scanf("%c", &bu);
	getline(cin, str);

	sort(str.begin(), str.end());
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ')
			alpha[cnt++] = str[i];
	}
	
	go(0, 0);
	return 0;

}