#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
int N, M, H, iResult = INT_MAX;
bool visited[34][34];

bool check()
{
    for (int i = 1; i <= N; ++i)
    {
        int iStart = i;
        for (int j = 1; j <= H; ++j)
        {
            if (visited[j][iStart])
                iStart++;
            else if (visited[j][iStart - 1])
                iStart--;
        }
        if (iStart != i)
            return false;
    }
    return true;
}

void go(int iHere, int iCount)
{
    if (iCount > 3 || iCount >= iResult)
        return;
    if (check())
    {
        iResult = min(iResult, iCount);
        return;
    }

    for (int i = iHere; i <= H; ++i)
    {
        for (int j = 1; j < N; j++) 
        {
            if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1])
                continue;
            visited[i][j] = 1;
            go(i, iCount + 1);
            visited[i][j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    cin >> N >> M >> H;

    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        visited[a][b] = 1;
    }
    go(1, 0);
    if (iResult == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << iResult;
    
    return 0;
}