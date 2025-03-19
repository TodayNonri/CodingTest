#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long S, C, iResult = 0;
vector<long long> v;

bool Check(int iMid)
{
    int iCount = 0;

    for (int i = 0; i < S; ++i)
    {
        iCount += v[i] / iMid;
    }

    return iCount >= C;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> S >> C;
    v.resize(S);

    long long iLow = 1, iHigh = 0, iTotalLength = 0;
    for (int i = 0; i < S; ++i)
    {
        cin >> v[i];
        iHigh = max(iHigh, v[i]);
        iTotalLength += v[i];  
    }

    while (iLow <= iHigh)
    {
        long long iMid = (iLow + iHigh) / (long long)2;

        if (Check(iMid))
        {
            iLow = iMid + 1;
            iResult = iMid;
        }
        else
        {
            iHigh = iMid - 1;
        }
    }

     cout << iTotalLength - (C * iResult);

    return 0;
}
