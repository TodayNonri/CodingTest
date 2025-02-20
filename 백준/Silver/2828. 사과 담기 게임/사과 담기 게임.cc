#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int N, M, J;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N>> M>>J;

	int left = 1;
	int right = left + M - 1;
	int iCount = 0;
	vector<int> vApplePosition;
	vApplePosition.resize(J);
	for (int i = 0; i < J; ++i)
	{
		cin >> vApplePosition[i];
	}

	for (int i = 0; i < J; ++i)
	{
		if (vApplePosition[i] >= left && vApplePosition[i] <= right)
			continue;
		
		for (int j = 0; j < N; ++j)
		{
			if (vApplePosition[i] < left)
			{
				iCount++;
				left--;
				right--;
			}
			else if (vApplePosition[i] > right)
			{
				iCount++;
				left++;
				right++;
			}
			else
				break;
		}

	}

	cout << iCount << endl;


	return 0;
}
