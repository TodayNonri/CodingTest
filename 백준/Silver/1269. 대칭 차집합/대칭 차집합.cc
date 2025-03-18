#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

int N, M, iResult = 0;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    vector<int>vA(N);
    map<int, int> mA;
    map<int, int> mB;
    vector<int>vB(M);
    for (int i = 0; i < N; ++i)
    {
        cin >> vA[i];
        mA[vA[i]] = 1;
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> vB[i];
        mB[vB[i]] = 1;
    }

    for (int i = 0; i < N; ++i)
    {
        if (mB[vA[i]] == 0)
            ++iResult;
    }
    for (int i = 0; i < M; ++i)
    {
        if (mA[vB[i]] == 0)
            ++iResult;
    }


    cout << iResult<<"\n";

    return 0;
}
