#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int N, M, T, K, ret = 0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int earth[50][50] = { 0, };
int visited[50][50] = { 0, };

void Dfs(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;

		if(earth[ny][nx] == 1 && visited[ny][nx] == 0)
			Dfs(ny, nx);
	} 

	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vResult;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		ret = 0;
		cin >> M >> N >> K;

		for (int iy = 0; iy < N; ++iy) {
			for (int jx = 0; jx < M; ++jx) {
				earth[iy][jx] = 0;
				visited[iy][jx] = 0;
			}
		}

		for (int j = 0; j < K; ++j)
		{
			int x, y;
			cin >> x >> y;
			earth[y][x] = 1;
		}

		for (int a = 0; a < N; ++a)
		{
			for (int b = 0; b < M; ++b)
			{
				if (earth[a][b] == 1 && visited[a][b] == 0)
				{
					Dfs(a, b);
					ret++;
				}
			}
		}
		vResult.push_back(ret);
	}

	for (auto& r : vResult)
	{
		cout << r<<"\n";
	}


	return 0;
}
