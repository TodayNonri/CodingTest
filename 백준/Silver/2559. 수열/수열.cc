#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, k;
int temp, psum[100001], ret = -10000004;

int main()
{
	cin >> n>> k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> temp;
		psum[i] = psum[i - 1] + temp;
	}

	for (int i = k; i <= n; ++i)
	{
		ret = max(ret, psum[i] - psum[i - k]);
	}
	cout << ret << "\n";

	return 0;
}
