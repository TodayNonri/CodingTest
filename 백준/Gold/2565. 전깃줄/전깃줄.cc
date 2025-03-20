#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <iomanip>

using namespace std;

int N;
int lis[504];
vector<pair<int, int>> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int a, b;
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        v.push_back({ a, b });
    }
    sort(v.begin(), v.end());
    int iLen = 0;
    for (int i = 0; i < N; ++i)
    {
        auto it = lower_bound(lis, lis + iLen, v[i].second);
        if (*it == 0)
            ++iLen;
        *it = v[i].second;
    }

    cout << N - iLen;
    return 0;
}
