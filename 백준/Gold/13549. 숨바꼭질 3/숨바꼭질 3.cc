#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, K;

int visited[100002] = { 0 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    visited[N] = 1;

    queue<int> q;

    q.push(N);

    while (q.size())
    {
        int iPos = q.front();
        q.pop();
        if (iPos == K)
        {
            cout << visited[iPos]-1;
            return 0;
        }
        for (int i = 0; i < 3; ++i)
        {
            if (i == 0)
            {
                if (iPos * 2 >= 100002 || iPos * 2 < 0 || visited[iPos * 2])
                    continue;

                visited[iPos * 2] = visited[iPos];
                q.push(iPos * 2);
            }
            else if (i == 1)
            {
                if (iPos - 1 < 0 || visited[iPos - 1])
                    continue;

                visited[iPos - 1] = visited[iPos] + 1;
                q.push(iPos - 1);
            }
            else
            {
                if (iPos + 1 >= 100002 || visited[iPos + 1])
                    continue;
                visited[iPos + 1] = visited[iPos] + 1;
                q.push(iPos + 1);
            }
        }
    }
    
    return 0;
}
