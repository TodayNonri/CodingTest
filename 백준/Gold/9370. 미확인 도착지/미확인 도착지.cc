#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1'000'000'000; 


int solve_one() 
{
    int n, m, t, s, g, h;
    cin >> n >> m >> t >> s >> g >> h;

    vector<vector<pair<int, int>>> adj(n + 1);   // (to, cost)

    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;         
        int w = d * 2;              
        if ((a == g && b == h) || (a == h && b == g))
            --w;                    

        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }

    vector<int> cand(t);
    for (int i = 0; i < t; ++i) cin >> cand[i];
    sort(cand.begin(), cand.end());

    vector<int> dist(n + 1, INF);
    using P = pair<int, int>;                         // (총거리, 정점)
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty()) {
        int dHere = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dHere != dist[u]) continue;

        for (auto& edge : adj[u]) 
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dHere + w) 
            {
                dist[v] = dHere + w;
                pq.push({ dist[v], v });
            }
        }
    }

    bool first = true;
    for (int v : cand) 
    {
        if (dist[v] & 1)
        {            
            if (!first) 
                cout << ' ';
            cout << v;
            first = false;
        }
    }
    cout << '\n';
    return 0;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  cin >> T;
    while (T--) solve_one();
    return 0;
}