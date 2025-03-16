#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, iResult = 0;

vector<pair<int, int>> v;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    int iLeft = v[0].first;
    int iRight = v[0].second;

    for (int i = 1; i < N; ++i)
    {
        if (iRight < v[i].first)
        {
            iResult += (iRight - iLeft);
            iLeft = v[i].first;
            iRight = v[i].second;
        }
        else if (iRight >= v[i].first && iRight <= v[i].second)
            iRight = v[i].second;
    }
    iResult += (iRight - iLeft);

    cout << iResult << "\n";
    return 0;
}
