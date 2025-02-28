#include <iostream>
#include <vector>

using namespace std;

int N, M, H, iResult = 100;

bool visited[34][14] = { false, };

bool Cal()
{
    for (int i = 1; i <= N; ++i)
    {
        int iStart = i;
        for (int j = 1; j <= H; ++j)
        {
            if (visited[j][iStart] == true)
                iStart++;
            else if (visited[j][iStart-1] == true)
                iStart--;
        }
        if (iStart != i)
            return false;
    }

    return true;
}

void Sadari(int iHere, int iCount)
{
    if (iCount > 3 || iCount >= iResult)
        return;

    if (Cal())
    {
        iResult = min(iResult, iCount);
        return;
    }

    for (int i = iHere; i <= H; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1])
                continue;

            visited[i][j] = true;
            Sadari(i, iCount + 1);
            visited[i][j] = false;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> H;

    int iInputY, iInputX;
    for (int i = 0; i < M; ++i)
    {
        cin >> iInputY >> iInputX;
        visited[iInputY][iInputX] = true;
    }

    Sadari(1, 0);

    if (iResult == 100)
    {
        cout << -1;
        return 0;
    }

    cout << iResult;

    return 0;
}
