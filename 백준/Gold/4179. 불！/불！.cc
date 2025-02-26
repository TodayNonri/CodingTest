#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int R, C;

char maze[1001][1001];
int Visited[1001][1001] = { 0, };
int VisitedFire[1001][1001] = { 0, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int iStartY, iStartX;
vector<pair<int, int>> vFire;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
    {
        cin >> maze[i];
        for (int j = 0; j < C; ++j)
        {
            if (maze[i][j] == 'J')
            {
                iStartY = i;
                iStartX = j;
            }
            else if (maze[i][j] == 'F')
            {
                vFire.push_back({ i, j });
            }
        }
    }

    queue<pair<int, int>> Fq;
    for (auto fire : vFire)
    {
        Fq.push(fire);
        VisitedFire[fire.first][fire.second] = 1;
    }

    while (!Fq.empty())
    {
        int x, y;
        tie(y, x) = Fq.front();
        Fq.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C || maze[ny][nx] == '#')
                continue;
            if (VisitedFire[ny][nx] != 0)
                continue;

            VisitedFire[ny][nx] = VisitedFire[y][x] + 1;
            Fq.push({ ny, nx });
        }
    }

    queue<pair<int, int>> Jq;
    Jq.push({ iStartY, iStartX });
    Visited[iStartY][iStartX] = 1;

    while (!Jq.empty())
    {
        int x, y;
        tie(y, x) = Jq.front();
        Jq.pop();

        if (y == 0 || x == 0 || y == R - 1 || x == C - 1)
        {
            cout << Visited[y][x]; 
            return 0;
        }

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= R || nx >= C || maze[ny][nx] == '#' || Visited[ny][nx] != 0 || VisitedFire[ny][nx] != 0 && VisitedFire[ny][nx] <= Visited[y][x] + 1)
                continue;

            Visited[ny][nx] = Visited[y][x] + 1;
            Jq.push({ ny, nx });
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
