#include <iostream>
#include <string>
using namespace std;

int num[500];

int main()
{
	string str;
	int Tcase1, Tcase2;
	char a;

	cin >> Tcase1;
	
	while (Tcase1--)
	{
		cin >> Tcase2 >> a;
		cin.ignore();
		
		if (a == 'C')
		{
			getline(cin, str);
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == ' ')
					continue;
				cout << str[i] - 64<<" ";
			}
		}
		else if (a == 'N')
		{
			for (int i = 0; i < Tcase2; i++)
				cin >> num[i];
			for (int i = 0; i < Tcase2; i++)
				cout << (char)(num[i]+'A'-1) << " ";
		}
		cout << endl;
	}
	return 0;
}