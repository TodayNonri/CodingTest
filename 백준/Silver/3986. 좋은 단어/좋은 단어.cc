#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, result = 0;
	vector<string> vecStr;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		vecStr.push_back(str);
	}

	for (int i = 0; i < n; ++i)
	{
		if (vecStr[i].size() & 1)
			continue;

		string str = vecStr[i];
		for (int j = 0; j < str.size(); ++j)
		{
			if (str[j] == str[j + 1])
			{
				str.erase(j, 2);
				j = max(-1, j - 2);
			}
			if (str.empty())
			{
				result++;
				break;
			}
		}
	}

	cout << result;
	return 0;
}
