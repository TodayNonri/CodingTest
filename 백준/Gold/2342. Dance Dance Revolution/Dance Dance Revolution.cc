#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>
#define MAX_N 100001 
using namespace std;

int dp[5][5][MAX_N], N;
vector<int> v;
int check(int iFrom, int iTo)
{
    if (iFrom == 0) 
        return 2;
    if (iFrom == iTo) 
        return 1;
    if (abs(iFrom - iTo) == 2)
        return 4;

    return 3;
}

int solve(int y, int x, int iTarget) 
{
    if (iTarget == N) 
        return 0;
    if (dp[y][x][iTarget] != -1)
        return dp[y][x][iTarget];

    int iLeft = solve(v[iTarget], x, iTarget + 1) + check(y, v[iTarget]);
    int iRight = solve(y, v[iTarget], iTarget + 1) + check(x, v[iTarget]);

    return dp[y][x][iTarget] = min(iLeft, iRight);
}
int main()
{
    while (true)
    {
        int num;
        cin >> num;
        if (num == 0) 
            break;
        v.push_back(num);
    }
    memset(dp, -1, sizeof(dp));
    N = v.size();
    cout << solve(0, 0, 0) << '\n';
    return 0;
}
