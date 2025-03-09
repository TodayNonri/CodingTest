#include <iostream>
#include <vector>

using namespace std;

int R, C, T, iResult = 0;
int iRoom[51][51] = { 0 };
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> vCleaner;

void Explosive()
{
    int temp[51][51] = { 0 };

    for (int y = 0; y < R; ++y)
    {
        for (int x = 0; x < C; ++x)
        {
            if (iRoom[y][x] > 0)
            {
                int amount = iRoom[y][x] / 5;
                int count = 0;

                for (int i = 0; i < 4; ++i)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || nx < 0 || ny >= R || nx >= C || iRoom[ny][nx] == -1)
                        continue;

                    temp[ny][nx] += amount;
                    count++;
                }
                temp[y][x] += iRoom[y][x] - (amount * count);
            }
        }
    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (iRoom[i][j] != -1)
                iRoom[i][j] = temp[i][j];
        }
    }
}

void AirClean()
{
    int iTop = vCleaner[0].first;
    int iBottom = vCleaner[1].first;

    for (int i = iTop - 1; i > 0; --i)
        iRoom[i][0] = iRoom[i - 1][0];
    for (int i = 0; i < C - 1; ++i) 
        iRoom[0][i] = iRoom[0][i + 1];
    for (int i = 0; i < iTop; ++i)
        iRoom[i][C - 1] = iRoom[i + 1][C - 1];
    for (int i = C - 1; i > 1; --i)
        iRoom[iTop][i] = iRoom[iTop][i - 1];
    iRoom[iTop][1] = 0;

    // **아래쪽 공기청정기 (시계 방향)**
    for (int i = iBottom + 1; i < R - 1; ++i) iRoom[i][0] = iRoom[i + 1][0];
    for (int i = 0; i < C - 1; ++i) iRoom[R - 1][i] = iRoom[R - 1][i + 1];
    for (int i = R - 1; i > iBottom; --i) iRoom[i][C - 1] = iRoom[i - 1][C - 1];
    for (int i = C - 1; i > 1; --i) iRoom[iBottom][i] = iRoom[iBottom][i - 1];
    iRoom[iBottom][1] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> T;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> iRoom[i][j];
            if (iRoom[i][j] == -1)
                vCleaner.push_back({ i, j });
        }
    }

    for (int i = 0; i < T; ++i)
    {
        Explosive();
        AirClean();
    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (iRoom[i][j] > 0)
                iResult += iRoom[i][j];
        }
    }

    cout << iResult;
    return 0;
}
