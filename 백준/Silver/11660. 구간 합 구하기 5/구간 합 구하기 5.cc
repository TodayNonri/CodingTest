#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1025][1025] = { 0 };
int sum[1025][1025] = { 0 };

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> arr[i][j];
            sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    int y1, x1, y2, x2;
    for (int i = 0; i < M; ++i)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] + sum[y1 - 1][x1 - 1] << "\n";
    }

    return 0;
}
