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

    vector<pair<long long, long long>> v;
    int iDeadLine, iCupRamen;
    for (int i = 0; i < N; ++i)
    {
        cin >> iDeadLine >> iCupRamen;
        v.push_back({ iDeadLine, iCupRamen });
    }
    sort(v.begin(), v.end());
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (auto p : v)
    {
        pq.push(p.second);
        if (pq.size() > p.first)
            pq.pop();
    }

    while(!pq.empty())
    {
        iResult += pq.top();
        pq.pop();
    }
    cout << iResult;

    return 0;
}