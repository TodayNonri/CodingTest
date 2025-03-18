#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, iResult = 0;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        iResult = 0;
        int A, B;
        cin >> A >> B;
        vector<int> vA(A);
        vector<int> vB(B);

        for (int i = 0; i < A; ++i)
            cin >> vA[i];
        for (int i = 0; i < B; ++i)
            cin >> vB[i];

        sort(vB.rbegin(), vB.rend());

        for (int i = 0; i < A; ++i)
        {
            int iValue = vA[i];
            for (int j = 0; j < B; ++j)
            {
                if (iValue > vB[j])
                {
                    iResult += B - j;
                    break;
                }
            }
        }
        cout << iResult<<"\n";
    }


    return 0;
}
