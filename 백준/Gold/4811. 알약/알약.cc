#include <iostream>
using namespace std;

long long dp[31][31];
long long N;

long long Func(int iWhole, int iNot_Whole)
{
    if (iWhole == 0 && iNot_Whole == 0)
        return 1;

    if (dp[iWhole][iNot_Whole])
        return dp[iWhole][iNot_Whole];
    long long& result = dp[iWhole][iNot_Whole];
    if (iWhole > 0)
        result += Func(iWhole - 1, iNot_Whole + 1);
    if (iNot_Whole > 0)
        result += Func(iWhole, iNot_Whole - 1);

    return result;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;
        cout << Func(N, 0) << "\n";
    }


    return 0;
}
