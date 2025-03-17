#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, iResult = INT_MAX;

vector<int> v;

bool Search(int iValue)
{
    int iResult = 0;

    for (int i = 0; i < M; ++i)
    {
        iResult += v[i] / iValue;
        if (v[i] % iValue)
            iResult++;
    }

    return iResult <= N;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    v.resize(M);
    int iLeft = 1, iRight = 0; 

    for (int i = 0; i < M; ++i)
    {
        cin >> v[i];
        iRight = max(iRight, v[i]);
    }

    int iMid = 0;
    while (iLeft <= iRight)
    {
        iMid = (iLeft + iRight) / 2;

        if (Search(iMid))
        {
            iResult = min(iResult, iMid);
            iRight = iMid - 1;
        }
        else
            iLeft= iMid + 1;
    }

    cout << iResult;
    return 0;
}
