#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>


using namespace std;

vector<int> vNum;
vector<char> vOper;

int N;
int iResult = -987654321;

int oper(char a, int b, int c)
{
    if (a == '+')
        return b + c;
    if (a == '-')
        return b - c;
    if (a == '*')
        return b * c;
}

void Go(int iHere, int iNum)
{
    if (iHere == vNum.size() - 1)
    {
        iResult = max(iResult, iNum);
        return;
    }
    Go(iHere + 1, oper(vOper[iHere], iNum, vNum[iHere + 1]));

    if (iHere + 2 <= vNum.size() - 1)
    {
        int temp = oper(vOper[iHere + 1], vNum[iHere + 1], vNum[iHere + 2]);
        Go(iHere + 2, oper(vOper[iHere], iNum, temp));
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    cin >> N;

    string strInput;
    cin >> strInput;
    for (int i = 0; i < N; ++i)
    {
        if (i % 2 == 0)
            vNum.push_back(strInput[i] - '0');
        else
            vOper.push_back(strInput[i]);
    }

    Go(0, vNum[0]);
    
    cout << iResult;
    
    return 0;
}