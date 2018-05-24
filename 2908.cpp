#include <iostream>
using namespace std;

int reverse(int n);

int main()
{
	int num1, num2,res;
	cin >> num1 >> num2;
	
	num1 = reverse(num1);
	num2 = reverse(num2);

	res = num1 > num2 ? num1 : num2;

	cout << res << endl;

	return 0;

}

int reverse(int n)
{
	n = n / 100 + ((n % 100) / 10) * 10 + (n % 10) * 100;

	return n;
}