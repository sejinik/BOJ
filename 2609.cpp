#include <iostream>
using namespace std;

int min(int x, int y)
{
	return x > y ? y : x;
}

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int x, y,big=1,small,a,b;
	cin >> x >> y;
	a = min(x, y); // ���� ������
	b = max(x, y); // ���� ū��

	if (x == 1)
		cout << a << endl << b << endl;

	else if (x == y)
		cout << x << endl << y << endl;

	else
	{
		for (int i = 2; i <= a; i++)
		{
			if (a%i == 0 && b%i == 0)
				big = i; // �ִ�����
			
		}
		
		for (int i = 1; i <= b; i++)
		{
			if (((a*i) % b) == 0)
			{
				small = a*i; // �ּҰ����
				break;
			}
		}
		cout << big << endl << small << endl;
	}
	return 0;
	

}