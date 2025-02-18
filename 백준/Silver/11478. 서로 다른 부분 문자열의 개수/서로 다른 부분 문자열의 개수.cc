#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
set<string> s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int result = 0;
	string str;

	cin >> str;

	for (int i = 1; i <= str.size(); ++i)
	{
		for (int j = 0; j < str.size(); ++j)
		{
			if (j + i > str.size())
				break;
			string temp = str.substr(j, i);
			s.insert(temp);
		}
	}

	cout << s.size();

	return 0;
}
