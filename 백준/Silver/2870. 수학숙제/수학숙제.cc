#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
string strResult;
vector<string> v;
int N;

void go()
{
	while (1)
	{
		if (strResult.size() && strResult.front() == '0')
			strResult.erase(strResult.begin());
		else
			break;
	}

	if (strResult.size() == 0) strResult = "0";
	v.push_back(strResult);
	strResult = "";
}

bool cmp(string a, string b)
{
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	vector<string> vStr;
	for (int i = 0; i < N; ++i)
	{
		string strInput;
		cin >>strInput;

		for (int j = 0; j < strInput.size(); ++j)
		{
			if (strInput[j] < 65)
				strResult += strInput[j];
			else if (strResult.size()) 
				go();
			
		}
		if (strResult.size())
			go();
	}

	sort(v.begin(), v.end(), cmp);

	for (auto& str : v)
		cout << str << "\n";

	return 0;
}
