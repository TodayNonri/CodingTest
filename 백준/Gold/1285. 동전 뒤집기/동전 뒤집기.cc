#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
int N, iResult = INT_MAX;
int board[21];

int Check()
{
    int iResult = 0;
    for (int i = 0; i < N; ++i)
    {

    }
    return iResult;
}

void Go(int iHere)
{
    if (iHere == N+1)
    {
        int iSum = 0;
        for (int i = 1; i < (1 << N) - 1; i*=2)
        {
            int iCount = 0;
            for (int j = 1; j <= N; ++j)
            {
                if (board[j] & i)
                    ++iCount;
            }
            iSum += min(iCount, N - iCount);
        }
        iResult = min(iResult, iSum);
        return;
    }
    Go(iHere + 1);
    board[iHere] = ~board[iHere];
    Go(iHere + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);

    cin >> N;

    string strInput;
    for (int i = 1; i <= N; ++i)
    {
        cin >> strInput;
        int iValue = 1;
        for (int j = 0; j < N; ++j)
        {
            if (strInput[j] == 'T')
                board[i] |= iValue;
            iValue *= 2;
        }
    }

    Go(1);

    cout << iResult;
    return 0;
}