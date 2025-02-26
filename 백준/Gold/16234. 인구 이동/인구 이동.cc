#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N, L, R, iResult = 0;
int Country[50][50];
bool Visited[50][50];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool MovePeople(int sy, int sx, vector<pair<int, int>>& vConnected, int& iSum)
{
    queue<pair<int, int>> q;
    q.push({ sy, sx });
    Visited[sy][sx] = true;

    vConnected.push_back({ sy, sx });
    iSum = Country[sy][sx];
    int iCount = 1;
    bool bMoved = false;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N || Visited[ny][nx])
                continue;

            int diff = abs(Country[y][x] - Country[ny][nx]);
            if (diff >= L && diff <= R)
            {
                Visited[ny][nx] = true;
                q.push({ ny, nx });
                vConnected.push_back({ ny, nx });
                iSum += Country[ny][nx];
                iCount++;
                bMoved = true;
            }
        }
    }

    return bMoved;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Country[i][j];
        }
    }

    while (true)
    {
        bool bFlag = false;
        fill(&Visited[0][0], &Visited[0][0] + 50 * 50, false);
        vector<vector<pair<int, int>>> vConnectedList;
        vector<int> vAverages;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (!Visited[i][j])
                {
                    vector<pair<int, int>> vConnected;
                    int iSum = 0;

                    if (MovePeople(i, j, vConnected, iSum))
                    {
                        bFlag = true;
                        vConnectedList.push_back(vConnected);
                        vAverages.push_back(iSum / vConnected.size());
                    }
                }
            }
        }
        if (!bFlag) break;

        for (size_t i = 0; i < vConnectedList.size(); ++i)
        {
            for (auto pos : vConnectedList[i])
            {
                Country[pos.first][pos.second] = vAverages[i];
            }
        }

        iResult++;
    }

    cout << iResult;

    return 0;
}
