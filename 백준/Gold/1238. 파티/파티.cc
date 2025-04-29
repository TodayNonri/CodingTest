#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, X, u, v, w, iResult;
vector<pair<int, int>> adj[1001], adj2[1001];
int dist[1001], dist2[1001];
bool visited[1001];
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void dijkstra(int* dist, vector<pair<int, int>>* adj)
{
    pq.push({ 0, X });
    dist[X] = 0;

    while (pq.size())
    {
        int iHere = pq.top().second;
        int iHere_Dist = pq.top().first;
        pq.pop();
        if (dist[iHere] != iHere_Dist)
            continue;

        for (pair<int, int> there : adj[iHere])
        {
            int _dist = there.first, _there = there.second;
            if (dist[_there] > dist[iHere] + _dist)
            {
                dist[_there] = dist[iHere] + _dist;
                pq.push({ dist[_there], _there });
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);

    cin >> N>> M >> X;

    fill(dist, dist + 1001, INF);
    fill(dist2, dist2 + 1001, INF);

    for (int i = 0; i < M; ++i)
    {
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
        adj2[v].push_back({ w, u });
    }
    dijkstra(dist, adj);
    dijkstra(dist2, adj2);

    for (int i = 1; i <= N; ++i)
    {
        if (i == X) 
            continue;
        iResult = max(iResult, dist[i] + dist2[i]);
    }
    cout << iResult;


    return 0;
}