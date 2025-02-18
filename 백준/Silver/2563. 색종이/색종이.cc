#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int white[100][100] = { 0, };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, result = 0;

	vector<pair<int, int>> v;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		for(int j = y; j < y + 10; ++j)
			for (int k = x; k < x + 10; ++k)
				white[j][k] = 1;
	}

	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (white[i][j] == 1)
			{
				result++;
			}
		}
	}

	cout << result;

	return 0;
}
