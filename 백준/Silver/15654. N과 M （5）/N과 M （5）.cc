#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
vector<bool> visited;
vector<int> selected;

void dfs(int depth) 
{
    if (depth == M) 
    {
        for (int num : selected)
            cout << num << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; ++i) 
    {
        if (!visited[i])
        {  

            visited[i] = true;
            selected.push_back(v[i]);

            dfs(depth + 1);

            visited[i] = false;
            selected.pop_back();
        }
    }
}

int main() 
{
    cin >> N >> M;
    v.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < N; ++i)
        cin >> v[i];

    sort(v.begin(), v.end()); 

    dfs(0);

    return 0;
}
