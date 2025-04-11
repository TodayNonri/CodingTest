#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define INF 987654321;
int N;
int arr[103], pass[103];
int dp[103][10][10][10][2];


int mod(int iValue)
{
    return (iValue < 0) ? iValue + 10 : iValue % 10;
}

int Func(int iPos, int x, int y, int z, int iFlag)
{
    if (iPos == N)
        return 0;
    int& iResult = dp[iPos][x][y][z][iFlag];
    if (~iResult)
        return iResult;

    if (mod(x + arr[iPos]) == mod(pass[iPos]))
        return iResult = min(Func(iPos + 1, y, z, 0, 0), Func(iPos + 1, y, z, 0, 1));
    iResult = INF;
    int flag = iFlag ? 1 : -1;
    for (int i = 1; i <= 3; ++i)
    {
        iResult = min(iResult, 1 + Func(iPos, mod(x + i * flag), y, z, iFlag));
        iResult = min(iResult, 1 + Func(iPos, mod(x + i * flag), mod(y + i * flag), z, iFlag));
        iResult = min(iResult, 1 + Func(iPos, mod(x + i * flag), mod(y + i * flag), mod(z + i * flag), iFlag));
    }
    return iResult;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    cin >> N;

    string strInput;
    cin >> strInput;
    
    for (int i = 0; i < N; ++i)
        arr[i] = strInput[i] - '0';
    cin >> strInput;
    for (int i = 0; i < N; ++i)
        pass[i] = strInput[i] - '0';

    memset(dp, -1, sizeof(dp));
    cout << min(Func(0, 0, 0, 0, 0), Func(0, 0, 0, 0, 1));

    return 0;
}