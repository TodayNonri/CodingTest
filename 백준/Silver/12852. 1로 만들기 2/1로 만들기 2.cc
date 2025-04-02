#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

using namespace std;
int X;
int dp[1000004];

void Func(int iHere)
{
    if (iHere == 0)
        return;

    cout << iHere << " ";

    if (iHere % 3 == 0 && dp[iHere] == (dp[iHere / 3] + 1))
        Func(iHere / 3);
    else if (iHere % 2 == 0 && dp[iHere] == (dp[iHere / 2] + 1))
        Func(iHere / 2);
    else if ((iHere - 1 >= 0) && dp[iHere] == (dp[iHere] - 1) + 1)
        Func(iHere - 1);

    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> X;
    //memset(dp, 999999999, sizeof(dp));
    fill(dp, dp + 1000004, 987654321);

    dp[1] = 0;

    for (int i = 1; i <= X; ++i)
    {
        if (!(i % 3)) 
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        if (!(i % 2))
            dp[i] = min(dp[i / 2] + 1, dp[i]);

        dp[i] = min(dp[i - 1] + 1, dp[i]);
    }

    cout << dp[X] << "\n";
    Func(X);

    return 0;
}
