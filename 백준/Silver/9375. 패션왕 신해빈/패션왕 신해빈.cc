#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, int> mWear;
string str1, str2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c, n;
	vector<int> v;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			cin >> str1 >> str2;
			mWear[str2]++;
		}
		int result = 1;
		for (auto it = mWear.begin(); it != mWear.end(); ++it)
		{
			result *= (it->second) + 1;
		}
		result -= 1;
		mWear.clear();
		v.push_back(result);
		
	}

	for (auto& i : v)
		cout << i << "\n";

	return 0;
}
