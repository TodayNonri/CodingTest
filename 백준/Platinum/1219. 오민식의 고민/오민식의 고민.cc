#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
int n, s, e, m, visited[104], candi[104], a, b, c, ok;
vector<pair<int, int>> adj[104];
long long dist[104], cost[104];
const long long INF = 1e18;
queue<int> q;
int main(){
    scanf("%d %d %d %d\n", &n, &s, &e, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
    }
    for(int i = 0; i < n; i++)scanf("%lld", &cost[i]);
    fill(dist, dist + n, -INF);
    dist[s] = cost[s];
    for(int i = 0; i < n; i++){
        for(int here = 0; here < n; here++){
            for(pair<int, int> there : adj[here]){
                int _dist = there.second;
                int _there = there.first;
                if(dist[here] != -INF && dist[here] + cost[_there] - _dist > dist[_there]){
                    dist[_there] = dist[here] + cost[_there] - _dist;
                    if(i == n - 1) q.push(here);
                }
            }
        }
    }
    while(q.size()){
        int here = q.front(); q.pop();
        for(pair<int, int> there : adj[here]){
            if(there.first == e){
                ok = 1; break;
            }
            if(!visited[there.first]){
                visited[there.first] = 1;
                q.push(there.first);
            }
        }
        if(ok) break;
    }
    if(dist[e] == -INF)
        puts("gg");
    else if(ok)
        puts("Gee");
    else 
        printf("%lld\n", dist[e]);
    
    return 0;
}