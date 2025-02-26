#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

int N, M, iMax = 0;
char map[50][50];
int visited[50][50] = { 0, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
list<pair<int, int>> vLand;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> map[i];
    }
    for (int i = 0; i < N; ++i)
    {
        for(int j = 0; j<M; ++j)
        {
            if (map[i][j] == 'L')
                vLand.push_back({ i, j });
        }
    }

    queue<pair<int, int>> q;

    while (vLand.size())
    {
        fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
        visited[vLand.front().first][vLand.front().second] = 1;
        q.push(vLand.front());
        vLand.pop_front();
        while (q.size())
        {
            int x, y;
            tie(y, x) = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] != 0 || map[ny][nx] == 'W')
                    continue;

                visited[ny][nx] = visited[y][x] + 1;
                iMax = max(visited[ny][nx], iMax);
                q.push({ ny, nx });
            }
        }
        
    }

    cout << iMax-1;

    return 0;
}
