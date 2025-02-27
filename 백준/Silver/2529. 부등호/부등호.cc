#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<char> vStr;
vector<int> v;
int k;
bool visited[10] = { false,  };

bool dfs(int here, int count, vector<int>& vPrev)
{
    vPrev.push_back(v[here]);

    if (count == k)
    {
        for (auto i : vPrev)
            cout << i ;
        return true;
    }
    for (int i = 0; i < 10; ++i)
    {
        if (visited[v[i]])
            continue;

        if (vStr[count] == '<')
        {
            if (v[here] > v[i])
                continue;
        }
        else if (vStr[count] == '>')
        {
            if (v[here] < v[i])
                continue;
        }
        visited[v[i]] = true;
        bool bCheck = dfs(i, count+1, vPrev);
        vPrev.pop_back();
        visited[v[i]] = false;

        if (bCheck == true)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;
    vStr.resize(k);
    v.resize(10);
    for (int i = 0; i < k; ++i)
    {
        cin >> vStr[i];
    }
    for (int i = 0; i <10 ; ++i)
    {
        v[i] = i;
    }

    reverse(v.begin(), v.end());

    for(int i = 0; i<10; ++i)
    {
        vector<int> vPrev;
        visited[v[i]] = true;
        if (dfs(i, 0, vPrev))
            break;
        visited[v[i]] = false;
    }
    cout << "\n";
    reverse(v.begin(), v.end());
    fill(visited, visited + 10, false);
    for (int i = 0; i < 10; ++i)
    {
        vector<int> vPrev;
        visited[v[i]] = true;
        if (dfs(i, 0, vPrev))
            break;
        visited[v[i]] = false;
    }

    return 0;
}
