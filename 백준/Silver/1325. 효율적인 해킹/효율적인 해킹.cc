#include <bits/stdc++.h>
using namespace std;
 
vector<int> v[10001];
int dp[10001], mx, visited[10001], n, m, a, b;
 
int dfs(int here) {  
	visited[here] = 1;
	int ret = 1; 
	for(int there : v[here]){
		if(visited[there]) continue;
		ret += dfs(there); 
	} 
	return ret;
}
 
int main() { 
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cin >> n >> m;  
	while (m--) {
     	cin >> a >> b;  
	    v[b].push_back(a);
	} 
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		dp[i] = dfs(i); 
		mx = max(dp[i], mx);
	} 
	for (int i = 1; i <= n; i++) if (mx == dp[i]) cout << i << " "; 
	return 0;
}