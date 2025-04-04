#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M1, M2;
int C, P1, P2;
int dp[10004] ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1)
    {
        scanf("%d %d.%d", &N, &M1, &M2);
        if (N == 0)
            break;
        int iCost = M1 * 100 + M2;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; ++i)
        {
            scanf("%d %d.%d", &C, &P1, &P2);
            int iPrice = P1 * 100 + P2;
            for (int j = iPrice; j <= iCost; ++j)
                dp[j] = max(dp[j], dp[j - iPrice] + C);
        }
        cout << dp[iCost] << "\n";
    }
   
    return 0;
}
