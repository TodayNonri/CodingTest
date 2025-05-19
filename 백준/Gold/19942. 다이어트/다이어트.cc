#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
int N, iResult = INT_MAX;
int MinMp, MinMf, MinMs, MinMv;

struct food
{
    int p = 0;
    int f = 0;
    int s = 0;
    int v = 0;
    int c = 0;
};

vector<food> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);

    cin >> N;

    v.resize(N);
    vector<int> vRank;
    cin>> MinMp >> MinMf >> MinMs >> MinMv;
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i].p;
        cin >> v[i].f;
        cin >> v[i].s;
        cin >> v[i].v;
        cin >> v[i].c;
    }

    for (int i = 0; i < (1 << N); ++i)
    {
        food resultFood;
        vector<int> vTemp;
        for (int j = 0; j < N; ++j)
        {
            if (i & (1 << j))
            {
                resultFood.p += v[j].p;
                resultFood.f += v[j].f;
                resultFood.s += v[j].s;
                resultFood.v += v[j].v;
                resultFood.c += v[j].c;
                vTemp.push_back(j + 1);
            }
        }
        if (resultFood.p>=MinMp && resultFood.f >= MinMf && resultFood.s >= MinMs && resultFood.v >= MinMv && iResult >= resultFood.c)
        {
            if (iResult > resultFood.c)
            {
                iResult = resultFood.c;
                vRank = vTemp;
            }
            else
            {
                if (vRank > vTemp)
                    vRank = vTemp;
            }
        }
    }
    if (iResult == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << iResult<<"\n";
    for (auto& i : vRank)
        cout << i<< " ";

    return 0;
}