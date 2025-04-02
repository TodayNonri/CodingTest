#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

using namespace std;
int T, W;
int dp[1002][2][34];
int peach[1002];

int Func(int iIndex, int iTree, int iCount)
{
    if (iCount < 0)
        return -1e9;
    if (iIndex == T)
        return 0;
    int &iResult = dp[iIndex][iTree][iCount];

    if (~iResult)
        return iResult;

    return iResult = max(Func(iIndex + 1, iTree ^ 1, iCount - 1), Func(iIndex + 1, iTree, iCount)) + (iTree == peach[iIndex] - 1);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T >> W;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < T; ++i)
        cin >> peach[i];

    cout << max(Func(0, 1, W - 1), Func(0, 0, W));

    return 0;
}
