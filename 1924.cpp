#include <iostream>
using namespace std;

int RES(int x, int y,int z[12]); // 요일 반환해주는 함수

int main()
{
	enum DAY { SUN, MON, TUE, WED, THU, FRI, SAT }; // 일요일 = 0 ~ 토요일 =6

	int x, y; // 입력받을 날짜
	int result; // 출력할 요일
	cin >> x >> y;

	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // 각 달마다 일수
	int mon2[12] = { 31,0 }; // 각 달마다 일수의 합

	for (int i = 1; i < 12; i++) // 각 달마다 일수의 합 구해서 넣기
	{
		mon2[i] = mon2[i - 1] + mon[i];
	}

	result = RES(x, y, mon2); // 요일 받아와서 결과값 넣어주기

	switch (result) // 요일별 출력
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

int RES(int x, int y, int z[12]) // 1월일땐 바로 7로나누고 2월부터는 그전월들의 일수합 7로 나누고 반환
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