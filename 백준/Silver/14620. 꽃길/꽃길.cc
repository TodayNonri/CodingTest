#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
int N, iResult = INT_MAX;
bool visited[11][11];
int board[11][11];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

bool Check(int y, int x)
{
    if (visited[y][x])
        return false;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            return false;
        if (visited[ny][nx])
            return false;
    }

    return true;
}

int SumFlower(int y, int x)
{
    int iSum = board[y][x];
    visited[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        iSum += board[ny][nx];
        visited[ny][nx] = true;
    }
    return iSum;
}

void DeleteFlower(int y, int x)
{
    int iSum = board[y][x];
    visited[y][x] = false;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = false;
    }
}

void Flower(int iCount, int iSum)
{
    if (iCount == 3)
    {
        iResult = min(iResult, iSum);
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (Check(i, j))
            {
                Flower(iCount + 1, iSum + SumFlower(i, j));
                DeleteFlower(i, j);
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    }

    Flower(0, 0);

    cout << iResult;

    return 0;
}