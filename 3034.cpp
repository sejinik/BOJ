#include <iostream>
using namespace std;

int main() {
	int Tcase;
	int W, H;

	cin >> Tcase >> W >> H;

	while (Tcase--) {
		int num;
		cin >> num;

		if (num <= H || num*num <= W*W + H*H) {
			cout << "DA" << endl;
		}
		else {
			cout << "NE" << endl;
		}
	}
	return 0;
}