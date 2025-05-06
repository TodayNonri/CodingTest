#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int N, K;
int visited[1000001];
int cnt[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    cin >> N>> K;
    
    queue<int> q;
    q.push(N);
    visited[N] = 1;
    cnt[N] = 1;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (auto i : { here - 1, here + 1, here * 2 })
        {
            if (i > 100000 || i < 0)
                continue;
            if (!visited[i])
            {
                q.push(i);
                visited[i] = visited[here] + 1;
                cnt[i] += cnt[here];
            }
            else if (visited[i] == visited[here] + 1)
            {
                cnt[i] += cnt[here];
            }
            
        }
    }

    cout << visited[K] - 1 << "\n";
    cout << cnt[K];
    
    return 0;
}