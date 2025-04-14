#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define max_n 200004
#define ll long long

const ll mod = 1e9 + 7;
int N, iValue;
ll ret = 1, _prev;
vector<ll> tree_cnt(max_n, 0), tree_sum(max_n, 0);
ll _sum(vector<ll>& tree, int iValue)
{
    ll _result = 0;
    int i = iValue;
    while (i) {
        _result += tree[i];
        i -= (i & -i);
    }
    return _result;
}
ll sum(vector<ll>& tree, int s, int e) 
{
    if (s > e) return 0;
    return (_sum(tree, e) - _sum(tree, s - 1));
}

void update(vector<ll>& tree, int x, ll iValue) 
{
    int i = x;
    while (i <= max_n)
    {
        tree[i] += iValue;
        i += (i & -i);
    }
    return;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> iValue; iValue++;
        if (i != 1) 
        {
            ll left = iValue * sum(tree_cnt, 1, iValue - 1) - sum(tree_sum, 1, iValue - 1);
            ll right = sum(tree_sum, iValue + 1, max_n) - iValue * sum(tree_cnt, iValue + 1, max_n);
            ret *= (left + right) % mod;
            ret %= mod;
        }
        update(tree_cnt, iValue, 1);
        update(tree_sum, iValue, iValue);
    }
    cout << ret << "\n";
}