#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int M, N, K;

bool bPaper[101][101];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void DFS(int y, int x, int& cnt)
{
	cnt++;
	bPaper[y][x] = false;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N || bPaper[ny][nx] == false)
			continue;
		
		DFS(ny, nx, cnt);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> K;

	fill(&bPaper[0][0], &bPaper[M][N], true);

	priority_queue<int, vector<int>, greater<int>> Result;

	for (int i = 0; i < K; ++i)
	{
		int minX, minY,maxX, maxY;
		cin >> minX >> minY>>maxX>>maxY;
		for (int y = minY; y < maxY; ++y)
		{
			for (int x = minX; x < maxX; ++x)
			{
				bPaper[y][x] = false;
			}
		}
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int cnt = 0;

			if(bPaper[i][j] == true)
			{
				DFS(i, j, cnt);
			}

			if (cnt != 0)
				Result.push(cnt);
		}
	}

	cout << Result.size()<<"\n";
	while (!Result.empty())
	{
		cout << Result.top() << " ";
		Result.pop();
	}

	return 0;
}
