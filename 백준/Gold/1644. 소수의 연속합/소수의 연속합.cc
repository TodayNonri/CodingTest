#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, iResult = 0;

bool bChe[4'000'001]; 

vector<int> era(int iMaxNum)
{
    vector<int> v;
    for (int i = 2; i <= iMaxNum; ++i)
    {
        if (bChe[i])
            continue;
        for (int j = 2 * i; j <= iMaxNum; j += i)
            bChe[j] = 1;
    }
    for (int i = 2; i <= iMaxNum; ++i)
        if (bChe[i] == false)
            v.push_back(i);

    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    if (N == 1)
    {
        cout << 0;
        return 0;
    }

    vector<int> vEra = era(N);
    if (vEra.size() == 1 && vEra[0] == N)
    {
        cout << 1;
        return 0;
    }
    else if (vEra.size() == 1 && vEra[0] != N)
    {
        cout << 0;
        return 0;
    }

    int iLeft = 0, iRight = 0, sum = 0;
    while (iRight <= vEra.size()) 
    {
        if (sum < N && iRight < vEra.size())
            sum += vEra[iRight++];
        else
        {
            if (iLeft >= vEra.size())
                break;

            if (sum == N)
                iResult++;
            sum -= vEra[iLeft++];
        }
    }

    cout << iResult;

    return 0;
}
