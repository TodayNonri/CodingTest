#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int Board[12][12];

const int dy[] = { 0, 0, -1, 1 }; 
const int dx[] = { 1, -1, 0, 0 };

struct mal 
{
    int y, x, dir;
};

vector<mal> vMal;
vector<int> vStack[12][12];

bool isOut(int y, int x) 
{
    return y < 0 || x < 0 || y >= N || x >= N;
}

int reverseDir(int dir) 
{
    if (dir == 0) return 1;
    if (dir == 1) return 0;
    if (dir == 2) return 3;
    if (dir == 3) return 2;
    return -1;
}

bool move(int idx)
{
    mal& cur = vMal[idx];
    int y = cur.y;
    int x = cur.x;
    int dir = cur.dir;

    vector<int>& curStack = vStack[y][x];
    auto it = find(curStack.begin(), curStack.end(), idx);
    vector<int> moving(it, curStack.end());
    curStack.erase(it, curStack.end());

    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (isOut(ny, nx) || Board[ny][nx] == 2) 
    {
        cur.dir = reverseDir(dir);
        ny = y + dy[cur.dir];
        nx = x + dx[cur.dir];
        if (isOut(ny, nx) || Board[ny][nx] == 2) 
        {
            vStack[y][x].insert(vStack[y][x].end(), moving.begin(), moving.end());
            return false;
        }
    }

    if (Board[ny][nx] == 1)
        reverse(moving.begin(), moving.end());

    for (int id : moving) 
    {
        vMal[id].y = ny;
        vMal[id].x = nx;
    }

    vStack[ny][nx].insert(vStack[ny][nx].end(), moving.begin(), moving.end());

    if (vStack[ny][nx].size() >= 4)
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> Board[i][j];

    for (int i = 0; i < K; ++i) 
    {
        int y, x, dir;
        cin >> y >> x >> dir;
        --y; --x; --dir;
        vMal.push_back({ y, x, dir });
        vStack[y][x].push_back(i);
    }

    int iTurn = 1;
    while (iTurn <= 1000)
    {
        bool bFinished = false;
        for (int i = 0; i < K; ++i) 
        {
            if (move(i))
            {
                bFinished = true;
                break;
            }
        }
        if (bFinished)
            break;
        iTurn++;
    }

    if (iTurn > 1000)
        cout << -1;
    else
        cout << iTurn;

    return 0;
}
