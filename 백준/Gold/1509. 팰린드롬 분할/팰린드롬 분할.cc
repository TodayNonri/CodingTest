#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

string strInput;
int dp[2504][2504], dp2[2504];

int Func(int iHere) 
{
    if (iHere == strInput.size())
        return 0;
    if (dp2[iHere] != INT_MAX) 
        return dp2[iHere];
    int& iResult = dp2[iHere];
    for (int i = 1; iHere + i <= strInput.size(); i++)
    {
        if (dp[iHere][i]) iResult = min(iResult, Func(iHere + i) + 1);
    }
    return iResult;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> strInput;

    for (int i = 0; i < strInput.size(); ++i)
        dp[i][1] = 1;

    for (int i = 0; i < strInput.size() - 1; ++i)
        if (strInput[i] == strInput[i + 1])
            dp[i][2] = 1;

    for (int _size = 3; _size <= strInput.size(); _size++) {
        for (int j = 0; j + _size <= strInput.size(); j++) {
            if (strInput[j] == strInput[j + _size - 1] && dp[j + 1][_size - 2]) dp[j][_size] = 1;
        }
    }
    fill(dp2, dp2 + 2504, INT_MAX);
    cout << Func(0) << "\n";

    return 0;
}