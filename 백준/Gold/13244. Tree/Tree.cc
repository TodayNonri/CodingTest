#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vAdj[10001];
bool visited[10001];

bool Dfs(int iHere, int parent)
{
    visited[iHere] = true;

    for (int next : vAdj[iHere])
    {
        if (!visited[next]) 
        {
            if (!Dfs(next, iHere))
                return false;
        }
        else if (next != parent) 
            return false; 
    }

    return true;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) 
    {
        int N, M;
        cin >> N >> M;

        for (int i = 1; i <= N; ++i)
            vAdj[i].clear();

        for (int i = 0; i < M; ++i) 
        {
            int input1, input2;
            cin >> input1 >> input2;
            vAdj[input1].push_back(input2);
            vAdj[input2].push_back(input1);
        }

        fill(visited, visited + N + 1, false);
        bool isTree = Dfs(1, -1);

        if (isTree)
        {

            bool connected = true;
            for (int i = 1; i <= N; ++i)
            {
                if (!visited[i]) {
                    connected = false;
                    break;
                }
            }
            if (connected)
                cout << "tree" << "\n";
            else
                cout << "graph" << "\n";
        }
        else
            cout << "graph" << "\n";
    }

    return 0;
}
