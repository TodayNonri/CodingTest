#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, K, dp[101][100001];
struct Tour 
{
    int iTime, iPay;
};
Tour a[101], b[101];

int Func(int iHere, int iTime)
{
    if (iHere == N)
        return 0;
    int& iResult = dp[iHere][iTime];
    if (iResult)
        return iResult;
    iResult = -1e6;
    if (iTime - a[iHere].iTime >= 0)
        iResult = max(iResult, Func(iHere + 1, iTime - a[iHere].iTime) + a[iHere].iPay);
    if(iTime - b[iHere].iTime >= 0)
        iResult = max(iResult, Func(iHere + 1, iTime - b[iHere].iTime) + b[iHere].iPay);

    return iResult;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> a[i].iTime >> a[i].iPay >> b[i].iTime >> b[i].iPay;

    cout << Func(0, K);

    return 0;
}