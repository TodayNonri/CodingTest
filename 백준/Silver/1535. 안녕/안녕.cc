#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int dp[104], cost[104], happy[104];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> cost[i];
    for (int i = 0; i < N; ++i)
        cin >> happy[i];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 100; j > cost[i]; --j)
            dp[j] = max(dp[j], dp[j - cost[i]] + happy[i]);
    }

    cout << dp[100];

    return 0;
}
