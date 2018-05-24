#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	stack<char> s1;
	stack<char> s2;

	string str;
	int num;
	cin >> str >> num;

	for (int i = 0; i < str.length(); i++)
		s1.push(str[i]);
	
	while (num--)
	{
		char a, b;
		cin >> a;
		if (a == 'P')
		{
			cin >> b;
			s1.push(b);
		}
		else if (a == 'L')
		{
			if (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		else if (a == 'D')
		{
			if (!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
		else
			if(!s1.empty())
			s1.pop();
		
	}

	while(!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}

	while(!s2.empty())
	{	
		cout << s2.top();
			s2.pop();
	}
	cout << endl;

	return 0;
}