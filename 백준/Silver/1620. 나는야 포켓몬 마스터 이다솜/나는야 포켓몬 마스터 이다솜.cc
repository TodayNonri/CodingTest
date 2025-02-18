#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;

	map<string, int> mPoketmon;
	map<int, string> mPoketmon2;

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		mPoketmon[str] = i + 1;
		mPoketmon2[i + 1] = str;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> str;
		if (atoi(str.c_str()) == 0)
			cout << mPoketmon[str] << "\n";
		else
			cout << mPoketmon2[atoi(str.c_str())] << "\n";
	}
	return 0;
}
