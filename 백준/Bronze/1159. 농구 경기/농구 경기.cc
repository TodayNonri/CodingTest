#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
string temp, result;
vector<string> vName;
int main()
{

	cin >> n;
	int alpha[26] = {};
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		alpha[temp.front() - 'a']++;
	}

	for (int i = 0; i < 26; ++i)
	{
		if (alpha[i] >= 5)
			result+=((char)(i + 'a'));
	}

	if (result.empty())
		cout << "PREDAJA";
	else
		cout << result;
	

	return 0;
}
