#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct tagShark 
{
    int y, x, speed, dir, size;
};

int R, C, M;
vector<tagShark> SharkList;
int dy[] = { -1, 1, 0, 0 };  
int dx[] = { 0, 0, 1, -1 };

void MoveShark() 
{
    vector<vector<vector<tagShark>>> NewBoard(R, vector<vector<tagShark>>(C));

    for (auto& shark : SharkList)
    {
        if (shark.size == 0) 
            continue;

        int speed = shark.speed;
        if (shark.dir == 0 || shark.dir == 1)
            speed %= (2 * (R - 1));
        else  
            speed %= (2 * (C - 1));

        for (int i = 0; i < speed; ++i) 
        {
            int ny = shark.y + dy[shark.dir];
            int nx = shark.x + dx[shark.dir];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
            {  
                shark.dir ^= 1;  
                ny = shark.y + dy[shark.dir];
                nx = shark.x + dx[shark.dir];
            }
            shark.y = ny;
            shark.x = nx;
        }

        NewBoard[shark.y][shark.x].push_back(shark);
    }

    SharkList.clear();

    for (int i = 0; i < R; i++) 
    {
        for (int j = 0; j < C; j++) 
        {
            if (!NewBoard[i][j].empty()) 
            {
                sort(NewBoard[i][j].begin(), NewBoard[i][j].end(), [](tagShark& a, tagShark& b) {
                    return a.size > b.size;
                    });
                SharkList.push_back(NewBoard[i][j][0]);
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C >> M;

    for (int i = 0; i < M; i++) 
    {
        int y, x, s, d, z;
        cin >> y >> x >> s >> d >> z;
        y--; x--;  

        if (d == 1) 
            d = 0;
        else if (d == 2) 
            d = 1;
        else if (d == 3)
            d = 2;
        else if (d == 4)
            d = 3;

        SharkList.push_back({ y, x, s, d, z });
    }

    int iScore = 0;

    for (int i = 0; i < C; i++) 
    {
        for (int j = 0; j < R; j++) 
        {
            auto it = find_if(SharkList.begin(), SharkList.end(), [&](tagShark& s)
                {
                return s.y == j && s.x == i;
                });

            if (it != SharkList.end()) 
            {
                iScore += it->size;
                it->size = 0; 
                break;
            }
        }

        MoveShark();
    }

    cout << iScore << "\n";
    return 0;
}
