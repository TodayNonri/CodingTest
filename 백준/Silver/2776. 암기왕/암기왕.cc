#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, N, M;
    cin >> T;

    while (T--)
    {
        cin >> N;
        vector<int> v1(N);
        for (int i = 0; i < N; ++i)
            cin >> v1[i];

        cin >> M;
        vector<int> v2(M);
        for (int i = 0; i < M; ++i)
            cin >> v2[i];

        sort(v1.begin(), v1.end());

        for (int i = 0; i < M; ++i)
        {
            int iValue = v2[i];
            int iLeft = 0, iRight = v1.size() - 1;
            bool bFlag = false;
            while (iLeft <= iRight)
            {
                int iMid = (iLeft + iRight) / 2;
                if (v1[iMid] == iValue)
                {
                    bFlag = true;
                    break;
                }
                else if (v1[iMid] < iValue)
                    iLeft = iMid + 1;
                else if (v1[iMid] > iValue)
                    iRight = iMid - 1;
            }
            if (bFlag)
                cout << 1<<"\n";
            else
                cout << 0 << "\n";
        }

    }

    return 0;
}
