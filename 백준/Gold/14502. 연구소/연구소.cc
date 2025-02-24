#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int iResult = 0;
int arr[10][10] = { 0, };
bool visited[10][10] = { false, };
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> virusList;
vector<pair<int, int>> walliList;

void dfs(int y, int x) 
{
	for (int i = 0; i < 4; i++) 
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || arr[ny][nx] == 1) 
			continue;

		visited[ny][nx] = true;
		dfs(ny, nx);
	}
	return;
}

int solve()
{
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
	for (pair<int, int> b : virusList)
	{
		visited[b.first][b.second] = 1;
		dfs(b.first, b.second);
	}

	int iCount = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) 
			if (arr[i][j] == 0 && !visited[i][j])
				iCount++;
	}
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
			if (arr[i][j] == 0)
				walliList.push_back({i, j});
			else if (arr[i][j] == 2)
				virusList.push_back({ i, j });
		}
	}


	for (int i = 0; i < walliList.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			for (int k = 0; k < j; ++k)
			{
				arr[walliList[i].first][walliList[i].second] = 1;
				arr[walliList[j].first][walliList[j].second] = 1;
				arr[walliList[k].first][walliList[k].second] = 1;
				iResult = max(iResult, solve());
				arr[walliList[i].first][walliList[i].second] = 0;
				arr[walliList[j].first][walliList[j].second] = 0;
				arr[walliList[k].first][walliList[k].second] = 0;
			}
		}
	}

	cout << iResult << "\n";

	return 0;
}
