#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int N, iResult = 0;

struct tagBoard
{
    int Board[21][21];

    void RotateRight()
    {
        int temp[21][21] = { 0 };
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                temp[i][j] = Board[N - j - 1][i];

        memcpy(Board, temp, sizeof(Board));
    }
    void Move()
    {
        int temp[21][21] = { 0 };
        for (int i = 0; i < N; ++i)
        {
            int c = -1;
            bool bIsMixEx = false;
            for (int j = 0; j < N; ++j)
            {
                if (Board[i][j] == 0)
                    continue;
                if (bIsMixEx && Board[i][j] == temp[i][c])
                {
                    temp[i][c] *= 2;
                    bIsMixEx = false;
                }
                else
                {
                    temp[i][++c] = Board[i][j];
                    bIsMixEx = true;
                }
            }
            for (c++; c < N; c++)
                temp[i][c] = 0;
        }
        memcpy(Board, temp, sizeof(Board));
    }
    void Get_Max()
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                iResult = max(iResult, Board[i][j]);
            }
        }
    }

};

void Func(tagBoard _Board, int iHere)
{
    if (iHere == 5)
    {
        _Board.Get_Max();
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        tagBoard tempBoard = _Board;
        tempBoard.Move();
        Func(tempBoard, iHere + 1);
        _Board.RotateRight();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    tagBoard Board;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> Board.Board[i][j];
    Func(Board, 0);

    cout << iResult;

    return 0;
}