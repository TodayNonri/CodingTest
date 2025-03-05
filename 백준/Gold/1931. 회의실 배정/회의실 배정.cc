#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, iResult = 1;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int iStart, iEnd;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; ++i)
    {
        cin >> iStart >> iEnd;
        v.push_back({ iEnd, iStart });
    }

    sort(v.begin(), v.end());
    int iTemp = v[0].first;
    for (int i = 1; i < N; ++i)
    {
        if (v[i].second >= iTemp)
        {
            iTemp = v[i].first;
            ++iResult;
        }
    }

    cout << iResult;

    return 0;
}