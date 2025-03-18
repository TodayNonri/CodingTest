#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, iResult = INT_MAX;
int iLeft = 0, iRight = 0;
vector<int> v;

bool CheckBlueRay(int iMid)
{
    int iTemp = iMid;
    int iCount = 0;

    for (int i = 0; i < N; ++i)
    {
        if (iMid - v[i] < 0)
        {
            iMid = iTemp;
            ++iCount;
        }
        iMid -= v[i];
        
    }
    if (iMid != iTemp)
        iCount++;

    return iCount <= M;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    v.resize(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
        iRight += v[i];
        iLeft = max(iLeft, v[i]);
    }

    while (iLeft <= iRight)
    {
        int iMid = (iLeft + iRight) / 2;

        if (CheckBlueRay(iMid))
        {
            iResult = iMid;
            iRight = iMid - 1;
        }
        else
            iLeft = iMid + 1;
    }

    cout << iResult;
    return 0;
}
