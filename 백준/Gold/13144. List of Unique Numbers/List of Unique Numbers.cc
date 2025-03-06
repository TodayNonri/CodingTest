#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long N, iResult = 0;
long long llCount[100'001];
long long llNum[100'001];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> llNum[i];

    long long temp1= 0, temp2 = 0;
    while (temp1 < N)
    {
        if (!llCount[llNum[temp1]])
        {
            ++llCount[llNum[temp1]];
            ++temp1;
        }
        else
        {
            iResult += (temp1 - temp2);
            --llCount[llNum[temp2]];
            ++temp2;
        }
    }
    iResult += (long long)(temp1 - temp2) * (temp1 - temp2 + 1) / 2;
    cout << iResult;

    return 0;
}
