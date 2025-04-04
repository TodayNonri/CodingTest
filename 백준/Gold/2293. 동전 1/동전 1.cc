#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K;
int arr[10004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    arr[0] = 1;
    int temp;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        for (int j = temp; j <= K; ++j)
            arr[j] += arr[j - temp];
            
    }
    cout << arr[K];


    return 0;
}
