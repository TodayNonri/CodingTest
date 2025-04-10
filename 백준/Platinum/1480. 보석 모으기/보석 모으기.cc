#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, M, C;

int arr[24];
int dp[24][1 << 14][24];
int Func(int iHere, int iEat, int iCapacity)
{
    if (iHere == M)
        return 0;
    int& iResult = dp[iHere][iEat][iCapacity];

    if (iResult)
        return iResult;

    iResult = max(iResult, Func(iHere + 1, iEat, C));

    for (int i = 0; i < N; ++i)
    {
        bool isBeforeEat = (1 << i) & iEat;
        bool isCanEat = (iCapacity - arr[i]) >= 0;
        if (!isBeforeEat && isCanEat)
            iResult = max(iResult, Func(iHere, iEat | (1 << i), iCapacity - arr[i]) + 1);
    }
    return iResult;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> C;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    cout << Func(0, 0, C);

    return 0;
}