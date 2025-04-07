#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
using namespace std;

int Board[10][10];
int iResult = INT_MAX;
map<int, int> m;

bool check(int y, int x, int cnt)
{
    if (y + cnt > 10 || x + cnt > 10)
        return false;

    for (int i = y; i < y + cnt; i++)
    {
        for (int j = x; j < x + cnt; j++) 
        {
            if (Board[i][j] == 0) 
                return false;
        }
    }
    return true;
}
void draw(int y, int x, int cnt, int value) 
{
    for (int i = y; i < y + cnt; i++)
    {
        for (int j = x; j < x + cnt; j++)
        {
            Board[i][j] = value;
        }
    }
}

void dfs(int y, int x, int iCount)
{
    if (iCount >= iResult)
        return;
    if (x == 10)
    {
        dfs(y + 1, 0, iCount);
        return;
    }
    if (y == 10)
    {
        iResult = min(iResult, iCount);
        return;
    }
    if (Board[y][x] == 0)
    {
        dfs(y, x + 1, iCount); 
        return;
    }
    for (int i = 5; i >= 1; i--)
    {
        if (m[i] == 5) 
            continue;
        if (check(y, x, i)) 
        {
            m[i]++;
            draw(y, x, i, 0);
            dfs(y, x + i, iCount + 1);
            draw(y, x, i, 1);
            m[i]--;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            cin >> Board[i][j];


    dfs(0, 0, 0);

    cout << (iResult == INT_MAX ? -1 : iResult);
    return 0;
}
