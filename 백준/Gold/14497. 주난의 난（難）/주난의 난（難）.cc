#include <iostream>
#include <queue>
#include <vector>
#include <string> 
#include <cstring> 

using namespace std;

#define MAX_V 300
int N, M;
int iStartY, iStartX, iGoalY, iGoalX;
char room[MAX_V][MAX_V];
int visited[MAX_V][MAX_V] = { 0, };
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> vFriendPos;
bool bfs(int y, int x)
{
    if (y == iGoalY - 1 && x == iGoalX-1)
    {
        return true;
    }

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;

        if (visited[ny][nx])
            continue;

        if (room[ny][nx] == '1')
        {
            vFriendPos.push_back({ ny, nx });
            continue;
        }
        else 
        {
            visited[ny][nx] = visited[y][x] + 1;
            if (bfs(ny, nx) == true)
                return true;
        }
    }
    return false;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    cin >> iStartY >> iStartX >> iGoalY >> iGoalX;
    
    string strInput;
    for (int i = 0; i < N; ++i)
    {
        cin >> strInput;
        for (int j = 0; j < strInput.size(); ++j)
        {
            room[i][j] = strInput[j];
        }
    }



    int iCount = 0;
    while (true)
    {
        iCount++;
        visited[iStartY - 1][iStartX - 1] = 1;
        if (bfs(iStartY - 1, iStartX - 1) == true)
        {
            cout << iCount << "\n";
            return 0;
        }

        for (pair<int, int> p : vFriendPos)
        {
            room[p.first][p.second] = '0';
        }
        vFriendPos.clear();
        memset(visited, 0, sizeof(visited));
    }


    return 0;
}
