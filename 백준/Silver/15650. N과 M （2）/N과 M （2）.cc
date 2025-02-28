#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void dfs(int start, int depth)
{
    if (depth == M)
    {  
        for (int num : v) 
            cout << num << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; ++i) 
    {
        v.push_back(i);       
        dfs(i + 1, depth + 1); 
        v.pop_back();         
    }
}

int main() 
{
    cin >> N >> M;
    dfs(1, 0);  
    return 0;
}
