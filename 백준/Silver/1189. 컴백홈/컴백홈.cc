#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int R, C, K, iResult = 0;
char map[5][5];
int visited[5][5] = { false, };

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void PathFind(int y, int x, int iCount)
{
    if (y == 0 && x == C - 1)
    {
        if (iCount == K)
            iResult++;

        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx] || map[ny][nx] == 'T')
            continue;

        visited[ny][nx] = true;
        PathFind(ny, nx, iCount + 1);
        visited[ny][nx] = false;

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C>>K;

    for (int i = 0; i < R; ++i)
    {
        string strInput;
        cin >> strInput;
        for (int j = 0; j < C; ++j)
            map[i][j] = strInput[j];
    }

    visited[R - 1][0] = true;
    PathFind(R - 1, 0, 1);

    cout << iResult;

    return 0;
}