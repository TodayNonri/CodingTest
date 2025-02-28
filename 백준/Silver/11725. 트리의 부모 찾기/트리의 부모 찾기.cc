#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> v;
vector<int> parent;

void bfs(int root) 
{
    queue<int> q;
    q.push(root);
    parent[root] = -1; 

    while (!q.empty()) 
    {
        int iHere = q.front();
        q.pop();

        for (int next : v[iHere]) 
        {
            if (parent[next] == 0)
            {  
                parent[next] = iHere; 
                q.push(next);
            }
        }
    }
}

int main()
{
    cin >> N;
    v.resize(N + 1);
    parent.resize(N + 1, 0);

    int iVertex1, iVertex2;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> iVertex1 >> iVertex2;
        v[iVertex1].push_back(iVertex2);
        v[iVertex2].push_back(iVertex1);
    }

    bfs(1);  

    for (int i = 2; i <= N; ++i) 
        cout << parent[i] << "\n";

    return 0;
}
