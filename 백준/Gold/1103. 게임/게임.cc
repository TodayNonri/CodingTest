#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

using namespace std;
int N, M, dp[54][54];

char Board[54][54];
bool Visited[54][54];
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int Down(int y, int x) 
{
    if (y < 0 || x < 0 || y >= N || x >= M || Board[y][x] == 'H')
        return 0;
    if (Visited[y][x]) 
    {
        cout << -1 << "\n";
        exit(0);
    }
    int& iResult = dp[y][x];
    if (iResult != -1)
        return iResult;

    Visited[y][x] = true;
    int iValue = (int)Board[y][x] - '0';
    for (int i = 0; i < 4; i++) 
    {
        int ny = y + dy[i] * iValue;
        int nx = x + dx[i] * iValue;
        iResult = max(iResult, Down(ny, nx) + 1);
    }
    Visited[y][x] = false;
    return iResult;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    string strInput;
    for (int i = 0; i < N; i++)
    {
        cin >> strInput;
        for (int j = 0; j < M; j++) 
        {
            Board[i][j] = strInput[j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << Down(0, 0) << "\n";
}
