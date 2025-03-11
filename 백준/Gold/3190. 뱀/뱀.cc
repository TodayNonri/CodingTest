#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int N, K, iCount = 0;

int Board[101][101] = { 0 };
bool visited[101][101] = { false };
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
queue<pair<int, char>> qMove;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    for (int i = 0; i < K; ++i)
    {
        int iY, iX;
        cin >> iY >> iX;
        Board[iY - 1][iX - 1] = 1;
    }

    int L;
    cin >> L;
    for (int i = 0; i < L; ++i)
    {
        int X;
        char C;
        cin >> X >> C;
        qMove.push({ X, C });
    }

    deque<pair<int, int>> dq;
    dq.push_back({ 0, 0 });
    visited[0][0] = true;
    int iDir = 1;

    while (true)
    {
        iCount++;
        if (!qMove.empty() && qMove.front().first == iCount - 1)
        {
            if (qMove.front().second == 'L')
            {
                iDir = (iDir + 3) % 4; 
            }
            else
            {
                iDir = (iDir + 1) % 4; 
            }
            qMove.pop();
        }

        int y = dq.front().first;
        int x = dq.front().second;

        int ny = y + dy[iDir];
        int nx = x + dx[iDir];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx])
            break;

        dq.push_front({ ny, nx });
        visited[ny][nx] = true;

        if (Board[ny][nx] != 1)
        {
            int rY = dq.back().first;
            int rX = dq.back().second;
            visited[rY][rX] = false;
            dq.pop_back();
        }
        else
        {
            Board[ny][nx] = 0;
        }
    }

    cout << iCount;
    return 0;
}
