#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, k;
vector<int> vDay;
vector<int> vMax;
int main()
{
	cin >> n>> k;

	for (int i = 0; i < n; ++i)
	{
		int iInput;
		cin >> iInput;
		vDay.push_back(iInput);
	}

	for (int i = 0; i <= n - k; ++i)
	{
		int iSum = 0;
		for (int j = i; j < i + k; ++j)
		{
			iSum += vDay[j];
		}
		vMax.push_back(iSum);
	}

	sort(vMax.begin(), vMax.end());

	cout << vMax.back() << "\n";

	
	return 0;
}
