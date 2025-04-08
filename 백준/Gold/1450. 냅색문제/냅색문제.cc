#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

long long N, C;
vector<int> v, v2;
long long arr[31];
int iResult;
void Func(int iHere, int iEnd, vector<int>& v, int iSum)
{
    if (iSum > C)
        return;
    if (iHere > iEnd)
    {
        v.push_back(iSum);
        return;
    }
    Func(iHere + 1, iEnd, v, iSum + arr[iHere]);
    Func(iHere + 1, iEnd, v, iSum);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> C;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    Func(0, N / 2 - 1, v, 0);
    Func(N / 2, N - 1, v2, 0);
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    for (int b : v)
    {
        if (C - b >= 0)
            iResult += ((int)(upper_bound(v2.begin(), v2.end(), C - b) - v2.begin()));
    }
    cout << iResult << "\n";
    return 0;
}