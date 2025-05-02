#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, L, R;
int iSum = 0;
int board[51][51];
bool visited[51][51];
vector<pair<int, int>>v;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void DFS(int y, int x, vector<pair<int, int>>& v)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx])
            continue;
        if (abs(board[ny][nx] - board[y][x]) >= L && abs(board[ny][nx] - board[y][x]) <= R)
        {
            visited[ny][nx] = true;
            v.push_back({ ny, nx });
            iSum += board[ny][nx];
            DFS(ny, nx, v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);

    cin >> N >> L >> R;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    }
    bool bEnd = false;
    int iCount = 0;
    while (true)
    {
        bEnd = false;
        fill(&visited[0][0], &visited[0][0] + 51 * 51, false);

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (!visited[i][j])
                {
                    v.clear();
                    visited[i][j] = true;
                    v.push_back({ i, j });
                    iSum = board[i][j];
                    DFS(i, j, v);
                    if (v.size() == 1)
                        continue;
                    for (pair<int, int>b : v)
                    {   
                        board[b.first][b.second] = iSum / v.size();
                        bEnd = true;
                    }
                }
            }
        }
        if (!bEnd)
            break;
        iCount++;
    }

    cout << iCount;

    return 0;
}