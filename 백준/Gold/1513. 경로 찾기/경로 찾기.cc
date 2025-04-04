#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M, C;
int arr[51][51], dp[51][51][51][51];
const int mod = 1000007;
int Func(int y, int x, int iCount, int iPrev)
{
    if (y > N || x > M)
        return 0;
    if (y == N && x == M)
    {
        if (iCount == 0 && arr[y][x] == 0)
            return 1;
        if (iCount == 1 && arr[y][x] > iPrev)
            return 1;

        return 0;
    }

    int& iResult = dp[y][x][iCount][iPrev];
    if (~iResult)
        return iResult;

    iResult = 0;
    if (arr[y][x] == 0) {
        iResult = (Func(y + 1, x, iCount, iPrev) + Func(y, x + 1, iCount, iPrev)) % mod;
    }
    else if (arr[y][x] > iPrev) {
        iResult = (Func(y + 1, x, iCount - 1, arr[y][x]) + Func(y, x + 1, iCount - 1, arr[y][x])) % mod;
    }

    return iResult;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> C;
    memset(dp, -1, sizeof(dp));

    int y, x;
    for (int i = 1; i <= C; ++i)
    {
        cin >> y >> x;
        arr[y][x] = i;
    }
    for (int i = 0; i <= C; ++i)
        cout << Func(1, 1, i, 0) << " ";
    return 0;
}
