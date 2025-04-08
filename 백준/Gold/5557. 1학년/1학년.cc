#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;

int N;
long long arr[104];
long long dp[104][21];

long long Func(int iIndex, int iSum)
{
    if (iSum > 20 || iSum < 0)
        return 0;
    long long& ret = dp[iIndex][iSum];

    if (ret)
        return ret;

    if (iIndex == N - 2)
    {
        if (iSum == arr[N - 1])
            return 1;
        return 0;
    }

    ret += Func(iIndex + 1, iSum + arr[iIndex + 1]);
    ret += Func(iIndex + 1, iSum - arr[iIndex + 1]);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    cout << Func(0, arr[0]);
    return 0;
}