#include <iostream>
#include <string>
using namespace std;

string arr[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
string multi[10] = { "","0","00","000","0000","00000","000000","0000000","00000000","000000000" };

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	int fir = 0, sec = 0;
	int three = 0;

	for (int i = 0; i < 10; i++) {
		if (arr[i] == a)
			fir = i;
		if (arr[i] == b)
			sec = i;
		if (arr[i] == c)
			three = i;
	}

	if (a == "black" && b == "black") {
		printf("0\n");
		return 0;
	}

	if (a != "black")
		cout << fir << sec << multi[three] << "\n";
	else 
		cout << sec << multi[three] << "\n";
	return 0;

}