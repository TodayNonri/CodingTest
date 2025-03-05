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

    vector<pair<int, int>> v;
    int iCost, iDay;

    for (int i = 0; i < N; ++i)
    {
        cin >> iCost>> iDay;
        v.push_back({ iDay, iCost });
    }

    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; ++i)
    {
        pq.push(v[i].second);
        if (pq.size() > v[i].first)
            pq.pop();
    }

    while (!pq.empty())
    {
        iResult += pq.top();
        pq.pop();
    }
    cout << iResult;
    return 0;
}
