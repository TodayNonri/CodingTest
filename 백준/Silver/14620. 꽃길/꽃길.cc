#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int N, iResult = INT_MAX;
bool visited[11][11] = { false };
int price[11][11] = { 0, };
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

void Flower(int y, int x, int iCount, int iPrice)
{
    visited[y][x] = true;

    bool bCheck = true;
    vector<pair<int, int>> flowerPos;
    flowerPos.push_back({ y, x });

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx])
        {
            bCheck = false;
            break;
        }
        flowerPos.push_back({ ny, nx });
    }

    if (!bCheck)
    {
        visited[y][x] = false;
        return;
    }

    for (auto& p : flowerPos)
    {
        visited[p.first][p.second] = true;
        iPrice += price[p.first][p.second];
    }

    if (iCount == 2)
    {
        iResult = min(iPrice, iResult);
    }
    else
    {
        for (int i = 1; i < N - 1; ++i)
        {
            for (int j = 1; j < N - 1; ++j)
            {
                if (!visited[i][j])
                    Flower(i, j, iCount + 1, iPrice);
            }
        }
    }

    for (auto& p : flowerPos)
        visited[p.first][p.second] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> price[i][j];
    }

    for (int i = 1; i < N - 1; ++i)
    {
        for (int j = 1; j < N - 1; ++j)
        {
            Flower(i, j, 0, 0);
        }
    }

    cout << iResult;

    return 0;
}