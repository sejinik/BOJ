#include <iostream>
using namespace std;

int d[1010];

int main()
{
	int num;
	cin >> num;
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= num; i++) {
		d[i] = d[i - 1] + 2 * d[i - 2];
		d[i] %= 10007;
	}
	cout << d[num] << endl;
	return 0;
}