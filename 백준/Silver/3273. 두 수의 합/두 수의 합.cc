#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    vector<int> vNum(N);
    for (int i = 0; i < N; ++i)
        cin >> vNum[i];

    sort(vNum.begin(), vNum.end());

    int iGoal;
    cin >> iGoal;

    int iLeft = 0, iRight = N-1;
    int iCount = 0;

    while (iLeft<iRight)
    {
        if (vNum[iLeft] + vNum[iRight] == iGoal)
        {
            ++iCount;
            iRight--;
        }
        else if (vNum[iLeft] + vNum[iRight] < iGoal)
            ++iLeft;
        else if (vNum[iLeft] + vNum[iRight] > iGoal)
            --iRight;
    }

    cout << iCount;

    return 0;
}
