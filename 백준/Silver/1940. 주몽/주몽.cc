#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, result = 0;
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < v.size()-1; ++i)
	{
		if (v[i] >= m)
			continue;

		for (int j = i+1; j < v.size(); ++j)
		{
			v[i] + v[j] == m ? result++ : result;
		}
	}

	cout << result << "\n";

	return 0;
}
