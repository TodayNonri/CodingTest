#include <iostream>
#include <queue>
#include <vector>
#include <cstring> 

using namespace std;

int N, K;
int visited[500001][2];  

int bfs()
{
    queue<pair<int, int>> q; 
    q.push({ N, 0 });
    visited[N][0] = 1;

    while (!q.empty()) 
    {
        int iNow = q.front().first;
        int iTime = q.front().second;
        q.pop();

        int brother = K + iTime * (iTime + 1) / 2;
        if (brother > 500000) 
            return -1; 

        if (visited[brother][iTime % 2]) 
            return iTime;

        for (int next : {iNow + 1, iNow - 1, iNow * 2})
        {
            if (next >= 0 && next <= 500000 && !visited[next][(iTime + 1) % 2]) 
            {
                visited[next][(iTime + 1) % 2] = 1;
                q.push({ next, iTime + 1 });
            }
        }
    }

    return -1;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    memset(visited, 0, sizeof(visited)); 

    if (N == K) 
    {
        cout << "0\n";
        return 0;
    }

    cout << bfs() << "\n";
    return 0;
}
