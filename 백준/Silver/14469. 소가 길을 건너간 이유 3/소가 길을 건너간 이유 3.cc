#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, iResult = 0;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int iArrive, iTestTime;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; ++i)
    {
        cin >> iArrive >> iTestTime;
        v.push_back({iArrive, iTestTime});
    }

    sort(v.begin(), v.end());

    iResult = v[0].first + v[0].second;
    for (int i = 1; i < N; ++i)
    {
        if (iResult >= v[i].first)
            iResult += v[i].second;
        else
            iResult = v[i].first + v[i].second;
    }

    cout << iResult;

    return 0;
}