#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif // _CONSOLE

	std::ios::sync_with_stdio(false);
	queue<int> q;

	int num;
	string str;
	cin >> num;
	
	while (num--)
	{
		cin >> str;

		if (str == "push")
		{
			int n;
			cin >> n;
			q.push(n);
		}
		else if (str == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << endl;
				q.pop();
			}
			else
				cout << "-1" << endl;
		}
		else if (str == "size")
		{
			cout << q.size() << endl;
		}
		else if (str == "empty")
		{
			if (!q.empty())
				cout << "0" << endl;
			else
				cout << "1" << endl;
		}

		else if (str == "front")
		{
			if (!q.empty())
				cout << q.front() << endl;
			else
				cout << "-1" << endl;
		}
		else
			if (!q.empty())
				cout << q.back() << endl;
			else
				cout << "-1" << endl;
	}
	return 0;
}