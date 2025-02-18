#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	string strInput;
	vector<pair<char, int>> vAlpha;
	for (int i = 0; i < 26; ++i)
	{
		vAlpha.push_back({ 'A' + i, 0 });
	}
	cin >> strInput;

	for (int i = 0; i < strInput.size(); ++i)
	{
		for (int j = 0; j < vAlpha.size(); ++j)
		{
			if (strInput[i] == vAlpha[j].first)
			{
				vAlpha[j].second++;
			}
		}
	}
	//팰린드롬 가능한지 체크 ABCCBBA   ABCBCBA
	int holsu = 0; char center;
	for (int i = 0; i < vAlpha.size(); ++i)
	{
		if (vAlpha[i].second % 2 == 1)
		{
			++holsu;
			center = vAlpha[i].first;
		}
	}
	if (holsu >= 2 )
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	for (int i = 0; i < vAlpha.size(); ++i)
	{
		for (int j = 0; j < vAlpha[i].second / 2; ++j)
		{
			cout << vAlpha[i].first;
		}
	}
	if(holsu)
		cout << center;
	for (int i = vAlpha.size()-1; i >= 0; --i)
	{
		for (int j = 0; j < vAlpha[i].second / 2; ++j)
		{
			cout << vAlpha[i].first;
		}
	}

	return 0;
}
