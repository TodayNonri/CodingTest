#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int board[301][301];
bool visited[301][301];
int Y1, X1, Y2, X2;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;
    cin >> Y1 >> X1 >> Y2 >> X2;
    Y1 -= 1;
    X1 -= 1;
    Y2 -= 1;
    X2 -= 1;
    string strInput;
    for (int i = 0; i < N; ++i)
    {
        cin >> strInput;
        for (int j = 0; j < M; ++j)
            board[i][j] = strInput[j] - '0';
    }


    queue<pair<int, int>> q;
    int iCount = 0;

    while (true)
    {
        fill(&visited[0][0], &visited[0][0] + 301 * 301, false);
        q.push({ Y1, X1 });
        visited[Y1][X1] = true;
        bool bFind = false;
        while (!q.empty())
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; ++i)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                    continue;
                if (visited[ny][nx])
                    continue;
                if (board[ny][nx] == 1)
                {
                    visited[ny][nx] = true;
                    board[ny][nx] = 0;
                    continue;
                }
                if (ny == Y2 && nx == X2)
                {
                    bFind = true;
                    break;
                }
                visited[ny][nx] = true;
                q.push({ ny, nx });
            }
            if (bFind)
                break;
        }
        ++iCount;
        if (bFind)
            break;
    }

    cout << iCount;
    return 0;
}