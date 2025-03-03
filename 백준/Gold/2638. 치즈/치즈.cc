#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M;
bool Cheese[102][102] = { false };
bool Visited[102][102] = { false };
int AirCount[102][102] = { 0 };  
vector<pair<int, int>> vAir;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void Dfs(int y, int x)
{
    Visited[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N + 1 || nx >= M + 1)
            continue;

        if (Visited[ny][nx])
            continue;

        if (Cheese[ny][nx])
        {
            AirCount[ny][nx]++; 
            continue;
        }

        Dfs(ny, nx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> Cheese[i][j];
        }
    }

    int iCount = 0;
    while (true)
    {
        fill(&AirCount[0][0], &AirCount[0][0] + 102 * 102, 0);
        fill(&Visited[0][0], &Visited[0][0] + 102 * 102, false);  
        ++iCount;

        Dfs(0, 0);

        bool bFlag = false;
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                if (Cheese[i][j])
                {
                    if (AirCount[i][j] >= 2) 
                        Cheese[i][j] = 0; 
                    else
                        bFlag = true;  
                }
            }
        }

        if (!bFlag)
        {
            cout << iCount;
            return 0;
        }
    }

    return 0;
}
