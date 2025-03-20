#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <iomanip>

using namespace std;

int N;

double Func(vector<double>& v)
{
    int n = v.size();
    double mx = -1e9;
    for (int i = 0; i < n; ++i)
    {
        double Curr = 1.0;
        for (int j = i; j < n; ++j)
        {
            Curr *= v[j];
            mx = max(mx, Curr);
        }
    }

    return mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    vector<double> v(N);

    for (int i = 0; i < N; ++i)
        cin >> v[i];

    double iResult = Func(v);

    cout << fixed << setprecision(3) << iResult;

    return 0;
}
