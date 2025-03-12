#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

int N, M, K, iResult = INT_MAX;
int BoardA[51][51];
int BoardB[51][51];

int visited[104][104];
int dir, sy, sx, ey, ex;
const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };

struct tagRotate
{
    int y, x, dis;
};

vector<tagRotate> vRotate;
vector<int> vIndex;
vector<pair<int, int>> vv;
void go(int y, int x, int first)
{
    if (!first && y == sy && x == sx) dir++;
    if (!first && y == sy && x == ex) dir++;
    if (!first && y == ey && x == ex) dir++;
    if (!first && y == ey && x == sx) dir++;
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (visited[ny][nx]) return;
    visited[ny][nx] = 1;
    vv.push_back({ ny, nx });
    go(ny, nx, 0);
}

void rotateAll(int y, int x, int cnt) 
{
    for (int i = 1; i <= cnt; i++)
    {
        sy = y - 1 * i;
        sx = x - 1 * i;
        ey = y + 1 * i;
        ex = x + 1 * i;
        vv.clear();
        dir = 0;
        memset(visited, 0, sizeof(visited));
        visited[sy][sx] = 1;
        vv.push_back({ sy, sx });
        go(sy, sx, 1);

        vector<int> vvv;
        for (pair<int, int> c : vv)vvv.push_back(BoardB[c.first][c.second]);
        rotate(vvv.rbegin(), vvv.rbegin() + 1, vvv.rend());
        for (int i = 0; i < vv.size(); i++) BoardB[vv[i].first][vv[i].second] = vvv[i];
    }
}

int Func()
{
    for (int i : vIndex) 
        rotateAll(vRotate[i].y, vRotate[i].x, vRotate[i].dis);
    int mn = INT_MAX;
    for (int i = 0; i < N; i++) 
    {
        int cnt = 0;
        for (int j = 0; j < M; j++)
            cnt += BoardB[i][j];

        mn = min(mn, cnt);
    }
    return mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> BoardA[i][j];

    int R, C, S;
    for (int i = 0; i < K; ++i)
    {
        cin >> R >> C >> S;
        R--; C--;
        vRotate.push_back({ R, C, S });
        vIndex.push_back(i);
    }

    do {
        memcpy(BoardB, BoardA, sizeof(BoardA));
        iResult = min(iResult, Func());
    } while (next_permutation(vIndex.begin(), vIndex.end()));


    cout << iResult;

    return 0;
}
