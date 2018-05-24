#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	stack<int> s;
	string str;
	int num,X;
	cin >> num;

	while (num--)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> X;
			s.push(X);
		}
		else if (str == "pop")
		{
			if (s.size() <= 0)
				cout << "-1";
			else
			{
				cout << s.top();
				s.pop();
			}
			cout << endl;
		}
		else if (str == "size")
			cout << s.size() << endl;

		else if (str == "empty")
			cout << s.empty() << endl;

		else
		{
			if (s.empty() == 1)
				cout << "-1";
			else
				cout<<s.top();
			cout << endl;
		}
	}
	return 0;
}