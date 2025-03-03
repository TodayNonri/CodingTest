#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

using namespace std; 

int N, M, iRoomCount, iRoomExtent = 1, iMaxExtent = 0;
int castle[51][51];
int roomNum[51][51];
int visited[51][51];

const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };

vector<int> vRoomSize;

int Dfs(int y, int x, int depth)
{
	visited[y][x] = 1;
	roomNum[y][x] = iRoomCount;
	int dir = 0;
	for (int i = 1; i < 16; i *= 2, ++dir)
	{
		if (!(castle[y][x] & i))
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny<0 || nx <0 || ny >= M || nx >= N ||visited[ny][nx])
				continue;
			depth = Dfs(ny, nx, depth+1);
		}
	}

	return depth;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> castle[i][j];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j])
				continue;
			vRoomSize.push_back((Dfs(i, j, 1)));
			iRoomCount++;
		}
	}
	

	//fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int dir = 0;
			for (int k = 1; k < 16; k *= 2, ++dir)
			{
				if ((castle[i][j] & k))
				{
					int ny = i + dy[dir];
					int nx = j + dx[dir];
					if (ny < 0 || nx < 0 || ny >= M || nx >= N)
						continue;
					if (roomNum[i][j] == roomNum[ny][nx])
						continue;

					iRoomExtent = max(iRoomExtent, vRoomSize[roomNum[i][j]] + vRoomSize[roomNum[ny][nx]]);
				}
			}
		}
	}

	sort(vRoomSize.begin(), vRoomSize.end(), greater<>());
	iMaxExtent = vRoomSize.front();

	cout << iRoomCount <<" " << iMaxExtent<< " "<< iRoomExtent;

	return 0;
}