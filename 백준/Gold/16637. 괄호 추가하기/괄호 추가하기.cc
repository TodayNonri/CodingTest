#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, iResult = -2147483647;
string str;

vector<int> vNum;
vector<char> vOper;

int Cal(char c, int a, int b)
{
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
}

void Func(int iHere, int iNum)
{
    if (iHere == vNum.size() - 1)
    {
        iResult = max(iResult, iNum);
        return;
    }

    Func(iHere + 1, Cal(vOper[iHere], iNum, vNum[iHere + 1]));
    
    if (iHere + 2 <= vNum.size() - 1) 
    {
        int temp = Cal(vOper[iHere + 1], vNum[iHere + 1], vNum[iHere + 2]);
        Func(iHere + 2, Cal(vOper[iHere], iNum, temp));
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> str;

    bool isNum = true;
    for (int i = 0; i < N; ++i)
    {
        if (isNum)
            vNum.push_back(str[i] - '0');
        else
            vOper.push_back(str[i]);

        isNum = !isNum;
    }
    Func(0, vNum[0]);
    cout << iResult;

    return 0;
}