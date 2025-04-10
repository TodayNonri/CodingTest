#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, W;
int px[1004], py[1004], dp[1004][1004];

int d(int a, int b)
{
	return abs(px[a] - px[b]) + abs(py[a] - py[b]);
}

int getSum(int a, int b)
{
	if (a == W + 1 || b == W + 1)
		return 0;
	if (dp[a][b])
		return dp[a][b];
	int next = max(a, b) + 1;

	return dp[a][b] = min(getSum(a, next) + d(b, next), getSum(next, b) + d(a, next));
}

void solve()
{
	int a = 0, b = 1;
	for (int i = 2; i < W + 2; ++i)
	{
		if (dp[i][b] + d(a, i) < dp[a][i] + d(b, i)) 
			puts("1"), a = i;
		else
			puts("2"), b = i;
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N>> W;
	px[0] = 1, py[0] = 1;
	px[1] = N, py[1] = N;

	for (int i = 2; i < W + 2; ++i)
		cin >> px[i] >> py[i];

	cout << getSum(0, 1)<<"\n";
	solve();

	return 0;
}