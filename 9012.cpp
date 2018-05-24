#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	string str,ans;
	int num,cnt;
	cin >> num;

	while (num--)
	{
		cnt = 0;
		ans = "";

		cin >> str;
		
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(')
				cnt++;
			else if (str[i] == ')')
			{
				if (cnt <= 0)
				{
					ans = "NO";
					break;
				}
				cnt--;
			}
		}
		
		if (cnt == 0 && ans != "NO")
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}