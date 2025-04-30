#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, M, iLast;
bool board[102][102];
bool visited[102][102];
vector<pair<int, int>> vCheese;
vector<pair<int, int>> vAir2;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void Dfs(int y, int x)
{
    if (visited[y][x])
        return;

    visited[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (board[ny][nx] == 1 && visited[ny][nx] == false)
        {
            vCheese.push_back({ ny, nx });
            visited[ny][nx] = true;
            continue;
        }
        Dfs(ny, nx);
    }
}

int main() 
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }

    int iCount = 0, iLast = 0;
    bool bEnd = false;
    while (true)
    {
        bEnd = true;
        memset(visited, false, sizeof(visited));
        ++iCount;
        vCheese.clear();
        Dfs(0, 0);

        iLast = vCheese.size();

        for (pair<int, int> cheese : vCheese)
            board[cheese.first][cheese.second] = 0;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (board[i][j] == 1)
                    bEnd = false;
            }
        }
        if (bEnd == true)
            break;
    }
    

    cout << iCount << "\n" << iLast;

    return 0;
}