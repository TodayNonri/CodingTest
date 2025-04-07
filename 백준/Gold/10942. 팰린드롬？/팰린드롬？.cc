#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;

int arr[2000];
int dp[2002][2002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; ++i)
        cin >> arr[i];

    for (int i = 1; i <= N; ++i)
        dp[i][i] = 1;

    for (int i = 1; i <= N; ++i)
        if (arr[i] == arr[i + 1])
            dp[i][i + 1] = 1;

    for (int _size = 2; _size <= N; _size++)
    {
        for (int i = 1; i <= N - _size; i++) 
        {
            if (arr[i] == arr[i + _size] && dp[i + 1][i + _size - 1])
                dp[i][i + _size] = 1;
        }
    }


    cin >> M;

    int S, E;
    for (int i = 0; i < M; ++i)
    {
        cin >> S >> E;
        cout << dp[S][E]<<"\n";
    }

    return 0;
}