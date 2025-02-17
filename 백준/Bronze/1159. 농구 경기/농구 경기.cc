#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
string temp;
vector<string> vName;
int main()
{

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		vName.push_back(temp);
	}
	int alpha[26] = {};
	for (int i = 0; i < n; ++i)
	{
		int index = vName[i].front() - 'a';
		alpha[index]++;
	}

	bool flag = false;
	for (int i = 0; i < 26; ++i)
	{
		if (alpha[i] >= 5)
		{
			flag = true;
			cout << (char)(i + 'a');
		}
	}
	
	if(flag == false)
		cout << "PREDAJA" << "\n";

	return 0;
}
