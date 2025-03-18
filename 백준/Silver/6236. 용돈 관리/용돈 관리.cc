#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, iResult = INT_MAX;
int iLow = 0, iHigh = 0;
vector<int> v;

bool Check(int iMid)
{
    int iResult = 0;
    int iMoney = iMid; // Mid : 출금액, 
    for (int i = 0; i < N; ++i)
    {
        if (iMoney - v[i] < 0)
        {
            iMoney = iMid;
            iResult++;
        }
        iMoney -= v[i];
    }
    if (iMoney != iMid)
        ++iResult;

    return iResult <= M;
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
        iLow = max(iLow, v[i]);
        iHigh += v[i];
    }

    while (iLow <= iHigh)
    {
        int iMid = (iLow + iHigh) / 2;
        if (Check(iMid))
        {
            iResult = iMid;
            iHigh = iMid - 1;
        }
        else
            iLow = iMid + 1;
    }

    cout << iResult;
    return 0;
}
