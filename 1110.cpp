#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int num;//숫자
	int x, y, first;
	int Count = 0;//사이클의 길이

	cin >> num;
	first = num;
	if (num < 10)
	{
		if (num == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		
		num = num * 11;
		Count++;
	}

	while (true)
	{
		
		x = num / 10 + num % 10;
		y = (num % 10) * 10 + x % 10;
		num = y;
		Count++;

		if (first == y)
		{
			cout << Count << endl;
			return 0;
		}
		
	}

	
	return 0;
}