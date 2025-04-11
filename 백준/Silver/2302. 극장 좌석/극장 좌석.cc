#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
int dp[41], cnt[41], temp;

int Func(int iPos)
{
    if (iPos >= N - 1)
        return 1;
    if (cnt[iPos])
        return Func(iPos + 1);
    if (~dp[iPos])
        return dp[iPos];
    int& iResult = dp[iPos];
    iResult = 0;
    if (!cnt[iPos + 1])
        iResult += (Func(iPos + 2) + Func(iPos + 1));
    else
        iResult += Func(iPos + 1);

    return iResult;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        cin >> temp;
        cnt[temp - 1] = 1;
    }
    memset(dp, -1, sizeof(dp));
    cout << Func(0) << "\n";

    return 0;
}