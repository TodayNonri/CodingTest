#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

int N, iResultMax = -1000000001, iResultMin = 1000000001;

vector<int> vNum;
vector<int> vCal;

void FindMinMax(int iIndex, int iCurrentValue, int iPlus, int iMinus, int iMul, int iDiv)
{
    if (iIndex == N - 1)
    {
        iResultMax = max(iResultMax, iCurrentValue);
        iResultMin = min(iResultMin, iCurrentValue);
        return;
    }
    if (iPlus)
        FindMinMax(iIndex + 1, iCurrentValue + vNum[iIndex + 1], iPlus - 1, iMinus, iMul, iDiv);
    if (iMinus)
        FindMinMax(iIndex + 1, iCurrentValue - vNum[iIndex + 1], iPlus , iMinus-1, iMul, iDiv);
    if (iMul)
        FindMinMax(iIndex + 1, iCurrentValue * vNum[iIndex + 1], iPlus , iMinus, iMul - 1, iDiv);
    if (iDiv)
        FindMinMax(iIndex + 1, iCurrentValue / vNum[iIndex + 1], iPlus , iMinus, iMul, iDiv - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    vNum.resize(N);
    vCal.resize(4);
    for (int i = 0; i < N; ++i)
        cin >> vNum[i];

    for (int i = 0; i < 4; ++i)
        cin >> vCal[i];

    FindMinMax(0, vNum[0], vCal[0], vCal[1], vCal[2], vCal[3]);

    cout << iResultMax << "\n" << iResultMin;
    return 0;
}
