#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 0, -1, 0 };
vector<int> vDragon[4][11];
int iCount, N, x, y, d, g, arr[101][101];
void Func(int x, int y, int d, int g) 
{
    arr[x][y] = 1;
    for (int i = 0; i <= g; i++)
    {
        for (int dir : vDragon[d][i]) 
        {
            x += dx[dir];
            y += dy[dir];
            arr[x][y] = 1;
        }
    }
    return;
}
void makeDragon() 
{
    for (int i = 0; i < 4; i++)
    {
        vDragon[i][0].push_back(i);
        vDragon[i][1].push_back((i + 1) % 4);
        for (int j = 2; j <= 10; j++)
        {
            int n = vDragon[i][j - 1].size();
            for (int k = n - 1; k >= 0; k--) 
                vDragon[i][j].push_back((vDragon[i][j - 1][k] + 1) % 4);
            for (int k = 0; k < n; k++) 
                vDragon[i][j].push_back(vDragon[i][j - 1][k]);
        }
    }
    return;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    makeDragon();
    for (int i = 0; i < N; i++) 
    {
        cin >> x >> y >> d >> g;
        Func(x, y, d, g);
    }
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++) 
            if (arr[i][j] && arr[i + 1][j] && arr[i + 1][j + 1] && arr[i][j + 1])
                iCount++;
    }
    cout << iCount << "\n";

    return 0;
}
