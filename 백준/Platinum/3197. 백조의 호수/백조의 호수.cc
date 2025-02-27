#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <cstring>

using namespace std;

#define MAX_V 1500
int R, C;
bool visited[MAX_V][MAX_V];  // ✅ vector → 배열로 변경 (메모리 절약)
char water[MAX_V][MAX_V];
vector<pair<int, int>> vSwan;
list<pair<int, int>> vWall;
queue<pair<int, int>> position;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = { 0, 1, 0, -1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;

    queue<pair<int, int>> waterQueue; // ✅ 녹일 얼음 위치 저장용 큐
    for (int i = 0; i < R; ++i)
    {
        string strInput;
        cin >> strInput;
        for (int j = 0; j < C; ++j)
        {
            water[i][j] = strInput[j];
            if (water[i][j] == 'L') vSwan.push_back({ i, j });
            if (water[i][j] != 'X') waterQueue.push({ i, j }); // ✅ 물 위치 저장
        }
    }

    int iCount = 0;
    queue<pair<int, int>> nextPosition;
    position.push(vSwan[0]);
    visited[vSwan[0].first][vSwan[0].second] = true;

    while (true)
    {
        queue<pair<int, int>> positionTemp;
        while (!position.empty())
        {
            int y = position.front().first;
            int x = position.front().second;
            position.pop();

            if (y == vSwan[1].first && x == vSwan[1].second)
            {
                cout << iCount;
                return 0;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) continue;
                
                visited[ny][nx] = true;
                if (water[ny][nx] == 'X')
                    positionTemp.push({ ny, nx }); // 다음 탐색을 위해 저장
                else
                    position.push({ ny, nx });
            }
        }

        // ✅ 물 확장 (얼음 녹이기)
        int waterSize = waterQueue.size();
        while (waterSize--)
        {
            int y = waterQueue.front().first;
            int x = waterQueue.front().second;
            waterQueue.pop();

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
                if (water[ny][nx] == 'X')
                {
                    water[ny][nx] = '.';
                    waterQueue.push({ ny, nx });
                }
            }
        }

        position = positionTemp;
        iCount++;
    }

    return 0;
}
