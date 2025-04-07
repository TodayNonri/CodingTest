#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 18;
bool isP[20];
double A, B, dp[20][20][20];
double go(int idx, int x, int y)
{
    if (idx == N) 
        return isP[x] || isP[y] ? 1.0 : 0.0;
    double& iResult = dp[idx][x][y];
    if (iResult > -0.5) 
        return iResult;
    iResult = 0.0;
    iResult += go(idx + 1, x + 1, y) * A * (1 - B);
    iResult += go(idx + 1, x + 1, y + 1) * A * B;
    iResult += go(idx + 1, x, y + 1) * (1 - A) * B;
    iResult += go(idx + 1, x, y) * (1 - A) * (1 - B);
    return iResult;
}
void era()
{
    fill(isP, isP + 20, 1);
    isP[0] = 0; isP[1] = 0;
    for (int i = 2; i <= 20; i++)
    {
        for (int j = i + i; j <= 20; j += i) 
        {
            isP[j] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    scanf("%lf %lf", &A, &B);
    A /= 100; B /= 100;
    era();
    memset(dp, -1, sizeof(dp));
    printf("%.6lf", go(0, 0, 0));
}