#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;                       
int board[1002][1002];          

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0,-1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);

    cin >> M >> N;              

    queue<pair<int, int>> qTomato;
    int iRemain = 0;           

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];

            if (board[i][j] == 1)           
                qTomato.push({ i, j });
            else if (board[i][j] == 0)      
                ++iRemain;
        }
    }

    int iDay = 0;

    while (!qTomato.empty() && iRemain)
    {
        int iTodayCnt = qTomato.size();    

        while (iTodayCnt--)
        {
            int y = qTomato.front().first;
            int x = qTomato.front().second;
            qTomato.pop();

            for (int dir = 0; dir < 4; ++dir)
            {
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (board[ny][nx] != 0)      
                    continue;

                board[ny][nx] = 1;           
                --iRemain;                   
                qTomato.push({ ny, nx });
            }
        }
        ++iDay;                              
    }

    if (iRemain)
        cout << -1;
    else
        cout << iDay;

    return 0;
}