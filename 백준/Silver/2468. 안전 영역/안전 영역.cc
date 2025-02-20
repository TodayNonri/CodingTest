#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int N, K;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int iLand[101][101];
bool bCheck[101][101];

void DFS(int y, int x)
{
	bCheck[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || N <= ny || N <= nx || iLand[ny][nx] <= K || bCheck[ny][nx] == true)
			continue;
		DFS(ny, nx);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
    
	int best = 1;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cin >> iLand[i][j];
	}

	for (int iCount = 0; iCount < 100; ++iCount)
	{
		K = iCount;
		fill(&bCheck[0][0], &bCheck[N][N], false);
		int Sum = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (iLand[i][j] > iCount && bCheck[i][j] == false)
				{
					DFS(i, j);
					Sum++;
				}
			}
		}
		best = max(best, Sum);
	}

	cout << best;


	return 0;
}
