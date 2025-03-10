#include <iostream>
#include <vector>
#include <climits>
#include <bit>

using namespace std;

int N, iResult = INT_MAX;
int Team[21][21];

int CountBit(int x) 
{
    int cnt = 0;
    while (x) 
    {
        cnt += (x & 1); 
        x >>= 1; 
    }
    return cnt;
}

int FindMin(vector<int>& vStart, vector<int>& vLink)
{
    int iSumStart = 0, iSumLink = 0;

    pair<int, int> ret = { 0, 0 };
    for (int i = 0; i < N / 2; i++) 
    {
        for (int j = 0; j < N / 2; j++) 
        {
            if (i == j) continue;
            ret.first += Team[vStart[i]][vStart[j]];
            ret.second += Team[vLink[i]][vLink[j]];
        }
    }
    return abs(ret.first - ret.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> Team[i][j];
    }

    for (int i = 0; i < (1 << N); ++i)
    {
        if (CountBit(i) != N / 2)
            continue;
        vector<int> vStart, vLink;
        for (int j = 0; j < N; ++j)
        {
            if (i & (1 << j))
                vStart.push_back(j);
            else
                vLink.push_back(j);
        }
        iResult = min(iResult, FindMin(vStart, vLink));
    }

    cout << iResult;
    return 0;
}
