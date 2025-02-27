#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MAX_V 20
int R, C;
bool visited[MAX_V][MAX_V];
char Board[MAX_V][MAX_V];

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };
string strAlpha = "";
int iMax = 0;

void bfs(int y, int x, int count)
{
    iMax = max(iMax, count);

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C)
            continue;
        if (strAlpha.find(Board[ny][nx]) != string::npos)
            continue;

        strAlpha += string(1, Board[ny][nx]);
        bfs(ny, nx, count+1);
        strAlpha.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; ++i)
    {
        string strInput;
        cin >> strInput;
        for (int j = 0; j < C; ++j)
            Board[i][j] = strInput[j];
    }

    visited[0][0] = 1;
    strAlpha += string(1, Board[0][0]);
    bfs(0, 0, 1);

    cout << iMax << "\n";


    return 0;
}
