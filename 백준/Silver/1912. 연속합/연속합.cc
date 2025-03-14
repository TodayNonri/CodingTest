#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <list>
using namespace std;



int main()
{
	int n, answer(0);
	int max = 0;

	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}

	for (int i = 0; i < n; ++i)
	{
		max += v[i];

		if (answer < max)
			answer = max;

		if (max < 0)
			max = 0;

	}

	if (!answer)
	{
		sort(v.begin(), v.end(), greater<>());
		answer = v[0];
	}

    cout << answer;

	return 0;
}
