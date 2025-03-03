#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M, myStart, myEnd;
vector<pair<int, int>> vNode[1001]; 
int dist[1001];

void FindPath(int start) 
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0; 
    pq.push({ 0, start });

    while (!pq.empty()) 
    {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (cost > dist[here])
            continue;

        for (auto there : vNode[here]) 
        {
            int next = there.first;
            int nextCost = cost + there.second;

            if (nextCost < dist[next])
            {
                dist[next] = nextCost;
                pq.push({ nextCost, next });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int iStart, iEnd, iCost;
        cin >> iStart >> iEnd >> iCost;
        vNode[iStart].push_back({ iEnd, iCost });
    }

    cin >> myStart >> myEnd;

    fill(dist, dist + 1001, INT_MAX); 
    FindPath(myStart);

    cout << dist[myEnd];
    return 0;
}
