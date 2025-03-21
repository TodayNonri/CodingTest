#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    const int MAX_BRAND = 50;
    int iFreq[MAX_BRAND + 1] = { 0 };

    for (int i = 0; i < N; i++)
    {
        int iBrend;
        cin >> iBrend;
        if (iBrend >= 1 && iBrend <= MAX_BRAND)
            iFreq[iBrend]++;
    }

    long long Result = 0;
    long long ways = 1;

    for (int k = 1; k <= MAX_BRAND; k++) 
    {
        if (iFreq[k] == 0)
            break;
        ways *= iFreq[k];
        Result += ways;
    }

    cout << Result << "\n";
    return 0;
}
