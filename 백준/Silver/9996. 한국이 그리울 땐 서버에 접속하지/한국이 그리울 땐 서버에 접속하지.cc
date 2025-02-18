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
	cin >> n;
	cin >> strInput;

	string strStart = strInput.substr(0, strInput.find('*'));
	string strEnd = strInput.substr(strInput.find('*') + 1);

	for (int i = 0; i < n; ++i)
	{
		string strName;
		cin >> strName;
		vName.push_back(strName);
	}

	for (int i = 0; i < n; ++i)
	{
		if (vName[i].size() < strStart.size() + strEnd.size())
			cout << "NE" << "\n";
		else
		{
			if (vName[i].substr(0, strStart.size()) == strStart && vName[i].substr(vName[i].size() - strEnd.size()) == strEnd)
				cout << "DA" << "\n";
			else
				cout << "NE" << "\n";
		}
	}
	return 0;
}
