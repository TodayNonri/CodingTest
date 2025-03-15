#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M, Room[10][10], temp[10][10], iResult = INT_MAX;
vector<pair<int, int>>v;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> extendCCTV(int iHere, int iDir)
{
    vector<pair<int, int>> _change;
    int y = v[iHere].first;
    int x = v[iHere].second;
    if (Room[y][x] == 1)
    {
        while (true)
        {
            int ny = y + dy[iDir];
            int nx = x + dx[iDir];
            if (ny >= 0 && ny < N && nx >= 0 && nx < M && Room[ny][nx] != 6)
            {
                if (Room[ny][nx] == 0) 
                {
                    Room[ny][nx] = 8;
                    _change.push_back({ ny, nx });
                }
                y = ny;
                x = nx;
            }
            else break;
        }
    }
    else if (Room[y][x] == 2)
    {
        for (int i = 0; i <= 2; i += 2)
        {
            int _y = y;
            int _x = x;
            while (true)
            {
                int ny = _y + dy[(iDir + i) % 4];
                int nx = _x + dx[(iDir + i) % 4];
                if (ny >= 0 && ny < N && nx >= 0 && nx < M && Room[ny][nx] != 6)
                {
                    if (Room[ny][nx] == 0)
                    {
                        Room[ny][nx] = 8; _change.push_back({ ny, nx });
                    }
                    _y = ny;
                    _x = nx;
                }
                else break;
            }
        }
    }
    else if (Room[y][x] == 3) 
    {
        for (int i = 0; i < 2; i++) 
        {
            int _y = y;
            int _x = x;
            while (true) {
                int ny = _y + dy[(iDir + i) % 4];
                int nx = _x + dx[(iDir + i) % 4];
                if (ny >= 0 && ny < N && nx >= 0 && nx < M && Room[ny][nx] != 6) {
                    if (Room[ny][nx] == 0)
                    {
                        Room[ny][nx] = 8; _change.push_back({ ny, nx }); 
                    }
                    _y = ny;
                    _x = nx;
                }
                else break;
            }
        }
    }
    else if (Room[y][x] == 4)
    {
        for (int i = 0; i < 3; i++)
        {
            int _y = y;
            int _x = x;
            while (true)
            {
                int ny = _y + dy[(iDir + i) % 4];
                int nx = _x + dx[(iDir + i) % 4];
                if (ny >= 0 && ny < N && nx >= 0 && nx < M && Room[ny][nx] != 6)
                {
                    if (Room[ny][nx] == 0)
                    {
                        Room[ny][nx] = 8; _change.push_back({ ny, nx }); 
                    }
                    _y = ny;
                    _x = nx;
                }
                else break;
            }
        }
    }
    else if (Room[y][x] == 5)
    {
        for (int i = 0; i < 4; i++)
        {
            int _y = y;
            int _x = x;
            while (true)
            {
                int ny = _y + dy[(iDir + i) % 4];
                int nx = _x + dx[(iDir + i) % 4];
                if (ny >= 0 && ny < N && nx >= 0 && nx < M && Room[ny][nx] != 6)
                {
                    if (Room[ny][nx] == 0) 
                    { 
                        Room[ny][nx] = 8; _change.push_back({ ny, nx }); 
                    }
                    _y = ny;
                    _x = nx;
                }
                else
                    break;
            }
        }
    }
    return _change;
}
void DFS(int here)
{
    if (here == v.size())
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (Room[i][j] == 0)
                    cnt++;
            }
        }
        iResult = min(cnt, iResult);
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        vector<pair<int, int>> _change = extendCCTV(here, k);
        DFS(here + 1);
        for (auto b : _change) Room[b.first][b.second] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Room[i][j];
            if (Room[i][j] != 6 && Room[i][j] != 0)
                v.push_back({ i, j });
        }
    }
    DFS(0);
    cout << iResult << "\n";

    return 0;
}