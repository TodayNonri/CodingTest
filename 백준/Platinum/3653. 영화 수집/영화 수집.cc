#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

int T, N, M;
int tree[200004], iTemp;
map<int, int> m;

void update(int iIndex, int iValue)
{
    while (iIndex < 200004)
    {
        tree[iIndex] += iValue;
        iIndex += (iIndex & -iIndex);
    }
}

int sum(int iIndex)
{
    int iResult = 0;
    while (iIndex > 0)
    {
        iResult += tree[iIndex];
        iIndex -= (iIndex & -iIndex);
    }
    return iResult;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    cin >> T;

    while (T--)
    {
        cin >> N >> M;
        memset(tree, 0, sizeof(tree));
        m.clear();
        int iUpdate_Idx = 100001;
        for (int i = 1; i <= N; i++) {
            update(i + iUpdate_Idx, 1);
            m[i] = i + iUpdate_Idx;
        }
        for (int i = 0; i < M; ++i)
        {
            cin >> iTemp;
            int idx = m[iTemp];
            cout << sum(idx) - 1 << " ";
            update(idx, -1);
            update(--iUpdate_Idx, 1);
            m[iTemp] = iUpdate_Idx;
        }
        cout << "\n";
    }
    return 0;
}