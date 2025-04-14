#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

int N, M;
int arr[1025][1025], bit[1025][1025];

void update(int y, int x, int iValue)
{
    while (y <= N)
    {
        int j = x;
        while (j <= N)
        {
            bit[y][j] += iValue;
            j += (j & -j);
        }
        y += (y & -y);
    }
}

int sum(int y, int x)
{
    int iResult = 0;
    while(y>0)
    {
        int j = x;
        while (j > 0)
        {
            iResult += bit[y][j];
            j -= (j & -j);
        }
        y -= (y & -y);
    }
    return iResult;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> arr[i][j];
            update(i, j, arr[i][j]);
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int iType;
        cin >> iType;
        if (iType)
        {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << sum(y2, x2) - sum(y1 - 1, x2) - sum(y2, x1 - 1) + sum(y1 - 1, x1 - 1)<<"\n";
        }
        else
        {
            int y, x, iValue;
            cin >> y >> x >> iValue;
            update(y, x, iValue - arr[y][x]);
            arr[y][x] = iValue;
        }
    }

    return 0;
}