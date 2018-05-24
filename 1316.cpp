#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string str;
	int Count = 0;
	int sejin;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		Count++;
		sejin = 0;
		for (int j = 0; j < str.size()-1; j++)
		{
			for (int k = j + 1; k < str.size(); k++)
			{
				if ((str[j] == str[k]) && (str[j] != str[k - 1]))
				{
					Count--;
					sejin = 1;
					break;
				}
			}
			if (sejin== 1)
				break;
		}

	}
	cout << Count << endl;
	return 0;
}