#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, L, iResult;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> L;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    int iIndex = 0, b = 0;
    for (int i = 0; i < N; ++i)
    {
        if (v[i].second <= iIndex)
            continue;
        if (iIndex < v[i].first)
        {
            b = (v[i].second - v[i].first) / L + ((v[i].second - v[i].first) % L ? 1 : 0); 
            iIndex = v[i].first + b * L;
        }
        else
        {
            b = (v[i].second - iIndex) / L + ((v[i].second - iIndex) % L ? 1 : 0);
            iIndex = iIndex + b * L;
        }
        iResult += b;
    }

    cout << iResult;

    return 0;
}