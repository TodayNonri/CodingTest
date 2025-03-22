#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int dist[16][16];
int dp[16][1 << 16];
int N;
const int INF = 987654321;

int TSP(int iHere, int iVisited)
{
    if (iVisited == (1 << N) - 1)
        return dist[iHere][0] == 0 ? INF : dist[iHere][0];

    int& iResult = dp[iHere][iVisited];
    if (iResult != -1)
        return iResult;

    iResult = INF;

    for (int i = 0; i < N; ++i)
    {
        if (iVisited & (1 << i)) 
            continue;
        if (dist[iHere][i] == 0) 
            continue;

        iResult = min(iResult, TSP(i, iVisited | (1 << i)) + dist[iHere][i]);
    }
    return iResult;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> dist[i][j];

    memset(dp, -1, sizeof(dp));

    cout << TSP(0, 1);

    return 0;
}