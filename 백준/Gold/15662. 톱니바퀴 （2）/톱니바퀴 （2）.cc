#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T; 
bool TopNi[1001][8]; 
queue<pair<int, int>> RotateQ; 

void rotate(int iIndex, int iDir) 
{
    if (iDir == 1)
    { 
        bool temp = TopNi[iIndex][7];
        for (int i = 7; i > 0; --i)
        {
            TopNi[iIndex][i] = TopNi[iIndex][i - 1];
        }
        TopNi[iIndex][0] = temp;
    }
    else
    { 
        bool temp = TopNi[iIndex][0];
        for (int i = 0; i < 7; ++i)
        {
            TopNi[iIndex][i] = TopNi[iIndex][i + 1];
        }
        TopNi[iIndex][7] = temp;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; ++i) 
    {
        string strInput;
        cin >> strInput;
        for (int j = 0; j < 8; ++j)
            TopNi[i][j] = strInput[j] - '0';
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) 
    {
        int iIndex, iRotate;
        cin >> iIndex >> iRotate;
        RotateQ.push({ iIndex - 1, iRotate });
    }

    while (!RotateQ.empty())
    {
        int index = RotateQ.front().first;
        int direction = RotateQ.front().second;
        RotateQ.pop();

        vector<pair<int, int>> rotations;
        rotations.push_back({ index, direction });

        int leftDir = direction;
        for (int left = index - 1; left >= 0; --left) 
        {
            if (TopNi[left][2] != TopNi[left + 1][6])
            {
                leftDir *= -1;
                rotations.push_back({ left, leftDir });
            }
            else 
                break;
        }

        int rightDir = direction;
        for (int right = index + 1; right < T; ++right) 
        {
            if (TopNi[right - 1][2] != TopNi[right][6])
            {
                rightDir *= -1;
                rotations.push_back({ right, rightDir });
            }
            else break;
        }

        for (auto& [idx, dir] : rotations) 
            rotate(idx, dir);
    }

    int result = 0;
    for (int i = 0; i < T; ++i) 
    {
        if (TopNi[i][0] == 1) result++;
    }
    cout << result << "\n";

    return 0;
}