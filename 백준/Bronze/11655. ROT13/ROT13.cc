#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
string strInput, result;
vector<string> vName;
int main()
{
	getline(cin, strInput);

	for (auto& c : strInput)
	{
		if (c >= 'A' && c <= 'Z')
		{
			if (c + 13 <= 'Z')
			{
				c = c + 13;
			}
			else
			{
				c = ('A'-1) + (13 - ('Z' - c));
			}
		}
		else if (c >= 'a' && c <= 'z')
		{
			if (c + 13 <= 'z')
			{
				c = c + 13;
			}
			else
			{
				c = ('a'-1) + (13 - ('z' - c));
			}
		}
	}

	cout << strInput << endl;
	return 0;
}
