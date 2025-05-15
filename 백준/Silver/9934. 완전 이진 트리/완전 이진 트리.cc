#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int node[1025];
vector<int> vResult[14];

int K;
int iNumber;

void preOder(int iStart, int iEnd, int iLevel)
{
    if (iStart > iEnd)
        return;
    if (iStart == iEnd)
    {
        vResult[iLevel].push_back(node[iStart]);
        return;
    }

    int iMid = (iStart + iEnd) / 2;
    vResult[iLevel].push_back(node[iMid]);
    preOder(iStart, iMid - 1, iLevel + 1);
    preOder(iMid + 1, iEnd, iLevel + 1);
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    cin >> K;
    int c = 0;
    iNumber = (1 << K) - 1;

    for (int i = 0; i < iNumber; ++i)
    {
        cin >> node[i];
    }

    preOder(0, iNumber, 1);

    for (int i = 1; i <= K; ++i)
    {
        for (auto& j : vResult[i])
            cout << j << " ";
        cout << "\n";
    }
    
    return 0;
}