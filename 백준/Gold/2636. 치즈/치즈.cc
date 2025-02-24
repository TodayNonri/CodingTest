#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int iResult = 0;
int arr[101][101] = { 0, };
bool visited[101][101] = { false, };
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> vCheese;
vector<pair<int, int>> vCheeseChange;
vector<pair<int, int>> vAir;

void bfs(int y, int x)
{
	visited[y][x] = true;
	for (int j = 0; j < 4; ++j)
	{
		int ny = y + dy[j];
		int nx = x + dx[j];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 1 || visited[ny][nx] == true)
			continue;

		bfs(ny, nx);
	}
}

int check()
{
	vCheeseChange.clear();
	int iCount = 0;
	fill(&visited[0][0], &visited[100][100], false);
	
	bfs(0, 0);
	for (int i = 0; i < vCheese.size(); ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int ny = vCheese[i].first + dy[j];
			int nx = vCheese[i].second + dx[j];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 1 || visited[ny][nx] == false)
				continue;

			vCheeseChange.push_back({ vCheese[i].first, vCheese[i].second });
			iCount++;

			break;
		}
	}

	for (int i = 0; i < vCheeseChange.size(); ++i)
	{
		arr[vCheeseChange[i].first][vCheeseChange[i].second] = 0;
	}
	vCheese.clear();
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (arr[i][j] == 1)
			{
				vCheese.push_back({ i, j });
			}
		}
	}

	if (!vCheese.empty())
		return 0;

	return iCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
			if(arr[i][j] == 1)
				vCheese.push_back({ i, j });
		}
	}

	int iSum = 0;
	int iCount = 0;
	while (true)
	{
		iCount = check();
		iSum++;
		if (iCount != 0)
			break;
	}

	cout << iSum<<"\n"<<iCount;

	return 0;
}
