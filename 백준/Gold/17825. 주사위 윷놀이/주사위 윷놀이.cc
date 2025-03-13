#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int Jusawi[14], Mal[4], N = 10;
int v[104];
vector<int> vAdj[54];

int Move(int iHere, int iCount)
{
    if (iHere == 100)
        return 100;  

    if (vAdj[iHere].size() >= 2) 
    {
        iHere = vAdj[iHere][1];
        iCount--; 
    }

    while (iCount--)
    {
        iHere = vAdj[iHere][0];
        if (iHere == 100)
            break;  
    }

    return iHere;
}

bool isMal(int iMalIndex, int iIndex)
{
    if (iMalIndex == 100)
        return false;

    for (int i = 0; i < 4; i++) 
    {
        if (i == iIndex)
            continue;
        if (Mal[i] == iMalIndex)
            return true;
    }
    return false;
}

void add(int iHere, int iThere)
{
    vAdj[iHere].push_back(iThere);
}

void setMap()
{
    for (int i = 0; i <= 19; i++)
        add(i, i + 1);

    add(5, 21); add(21, 22); add(22, 23); add(23, 24);
    add(15, 29); add(29, 30); add(30, 31); add(31, 24);
    add(10, 27); add(27, 28); add(28, 24); add(24, 25);
    add(25, 26); add(26, 20); add(20, 100);

    v[1] = 2; v[2] = 4; v[3] = 6; v[4] = 8; v[5] = 10;
    v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20;
    v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30;
    v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40;
    v[21] = 13; v[22] = 16; v[23] = 19; v[24] = 25;
    v[27] = 22; v[28] = 24; v[25] = 30; v[26] = 35;
    v[29] = 28; v[30] = 27; v[31] = 26;
}

int go(int iHere)
{
    if (iHere == N)
        return 0;

    int iResult = 0;
    for (int i = 0; i < 4; i++) 
    {
        int iTemp_idx = Mal[i];
        int iMal_idx = Move(iTemp_idx, Jusawi[iHere]);

        if (isMal(iMal_idx, i))
            continue;  

        Mal[i] = iMal_idx;
        iResult = max(iResult, go(iHere + 1) + v[iMal_idx]);
        Mal[i] = iTemp_idx; 
    }
    return iResult;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < N; i++)
        cin >> Jusawi[i];

    setMap();
    cout << go(0) << "\n"; 

    return 0;
}
