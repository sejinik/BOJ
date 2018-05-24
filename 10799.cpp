#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack<int> stack;
	string str;
	int sum = 0;
	cin >> str;
	
	for (int i = 0;i < str.length(); i++)
	{
		if (str[i] == '(')
			stack.push(i);
		
		else
		{
			if (i - stack.top() == 1)
			{
				stack.pop();
				sum += stack.size();
			}
			else
			{
				stack.pop();
				sum += 1;
			}
		}
	}
	cout << sum << endl;
	return 0;

}
