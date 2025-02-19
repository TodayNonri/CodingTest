#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int N, M, ret = 0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int miro[104][104] = { 0, };
int visited[104][104] = { 0, };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	string strInput;

	for (int i = 0; i < N; ++i)
	{
		cin >> strInput;
		for (int j = 0; j < M; ++j)
		{
			if (strInput[j] == '1')
				miro[i][j] = 1;
		}
	}

	visited[0][0] = 1;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	while (q.size())
	{
		int y, x, ny, nx;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			if (miro[ny][nx] == 0 || visited[ny][nx] != 0 
				||ny<0 || nx<0 || ny >= N || nx >= M)continue;

			q.push({ ny, nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}

	cout << visited[N-1][M-1] << "\n";

	return 0;
}
