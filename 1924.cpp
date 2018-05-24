#include <iostream>
using namespace std;

int RES(int x, int y,int z[12]); // ���� ��ȯ���ִ� �Լ�

int main()
{
	enum DAY { SUN, MON, TUE, WED, THU, FRI, SAT }; // �Ͽ��� = 0 ~ ����� =6

	int x, y; // �Է¹��� ��¥
	int result; // ����� ����
	cin >> x >> y;

	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // �� �޸��� �ϼ�
	int mon2[12] = { 31,0 }; // �� �޸��� �ϼ��� ��

	for (int i = 1; i < 12; i++) // �� �޸��� �ϼ��� �� ���ؼ� �ֱ�
	{
		mon2[i] = mon2[i - 1] + mon[i];
	}

	result = RES(x, y, mon2); // ���� �޾ƿͼ� ����� �־��ֱ�

	switch (result) // ���Ϻ� ���
	{
	case SUN:
		cout << "SUN" << endl;
		break;
	case MON:
		cout << "MON" << endl;
		break;
	case TUE:
		cout << "TUE" << endl;
		break;
	case WED:
		cout << "WED" << endl;
		break;
	case THU:
		cout << "THU" << endl;
		break;
	case FRI:
		cout << "FRI" << endl;
		break;
	case SAT:
		cout << "SAT" << endl;
		break;
	}
	
	return 0;
}

int RES(int x, int y, int z[12]) // 1���϶� �ٷ� 7�γ����� 2�����ʹ� ���������� �ϼ��� 7�� ������ ��ȯ
{
	if (x == 1)
	{
		return y % 7;
	}

	else
	{
		return (z[x - 2] + y) % 7;
	}
}