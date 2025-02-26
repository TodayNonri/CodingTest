#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N, S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >>S;

    vector<int> v(N + 1);
    vector<int> vSum(N + 1, 0);
    stack<int> st;
    int iResult = 2147483647;
    int iCount = 0;
    int iStart = 1;

    int iLeft = 1;
    int iRight = 1;
    for (int i = 1; i <= N; ++i)
    {
        cin >> v[i];
        iRight = i;
        vSum[i] = vSum[i - 1] + v[i];

        if (vSum[i] >= S)
        {
            while (vSum[i] >= S)
            {
                vSum[i] -= v[iLeft];
                iLeft++;
            }
            iCount = iRight - iLeft + 2;
            iResult = min(iCount, iResult);
        }
    }

    if (iResult == 2147483647)
    {
        cout << 0;
        return 0;
    }
    cout << iResult;

    return 0;
}