#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>


using namespace std;
const int MAX_N = 20;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
char board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int R, C, iResult = 1;

void dfs(int y, int x, int used, int len)
{
    iResult = max(iResult, len);
    for (int d = 0; d < 4; ++d)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C) 
            continue;
        int bit = 1 << (board[ny][nx] - 'A');
        if (used & bit) 
            continue;
        dfs(ny, nx, used | bit, len + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);

    cin >> R >> C;
    string strInput;
    for (int i = 0; i < R; ++i)
    {
        cin >> strInput;
        for (int j = 0; j < C; ++j)
            board[i][j] = strInput[j];
    }

    int startBit = 1 << (board[0][0] - 'A');
    dfs(0, 0, startBit, 1);

    cout << iResult;
    
    return 0;
}