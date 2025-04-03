#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int N, K;
int arr[10004];
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    fill(arr, arr + 10004, INF);
    arr[0] = 0;
    int temp;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        for (int j = temp; j <= K; ++j)
            arr[j] = min(arr[j], arr[j - temp] + 1);
    }

    if (arr[K] == INF)
        cout << -1;
    else
        cout << arr[K];


    return 0;
}
