#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N, M, iAnswer = 2147483647;
int map[50][50];
vector<pair<int, int>> vChicken;
vector<pair<int, int>> vHome;
vector<vector<int>> vChikenTable;

void Func(int iStart, vector<int>v)
{
    if (v.size() == M)
    {
        vChikenTable.push_back(v);
        return;
    }
    for (int i = iStart + 1; i < vChicken.size(); ++i)
    {
        v.push_back(i);
        Func(i, v);
        v.pop_back();
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                vHome.push_back({ i, j });
            if (map[i][j] == 2)
                vChicken.push_back({ i, j });
        }
    }

    vector<int> v;
    Func(-1, v);
    for (auto table : vChikenTable)
    {
        int iResult = 0;
        for (pair<int, int> home : vHome)
        {
            int iMin = 2147483647;
            for (int i : table)
            {
                int iDist = abs(home.first - vChicken[i].first) + abs(home.second - vChicken[i].second);
                iMin = min(iMin, iDist);
            }
            iResult += iMin;
        }
        iAnswer = min(iAnswer, iResult);
    }

    cout << iAnswer;

    return 0;
}
