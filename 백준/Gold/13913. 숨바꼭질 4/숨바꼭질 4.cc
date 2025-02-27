#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;

int visited[100'004] = {0, };
int Parents[100'004] = { -987654321, };


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    visited[N] = 1;
    fill(Parents, Parents + 100'004, -987654321);
    queue<int> q;
    q.push(N);

    while (q.size())
    {
        int iNow = q.front();
        q.pop();
        if (iNow == K)
        {
            break;
        }
        for (int iNext : {iNow + 1, iNow - 1, iNow * 2})
        {
            if (iNext < 0 || iNext >= 100'004)
                continue;
            if (visited[iNext])
                continue;

            visited[iNext] = visited[iNow] + 1;

            Parents[iNext] = iNow;
            q.push(iNext);
        }
    }

    int prev = K;
    cout << visited[K] - 1<<"\n";
    vector<int> v;
    v.push_back(K);
    while (true)
    {
        if (Parents[prev] == -987654321)
            break;
        v.push_back(Parents[prev]);
        prev = Parents[prev];
    }
    
    reverse(v.begin(), v.end());
    for (auto i : v)
        cout << i << " ";

    return 0;
}