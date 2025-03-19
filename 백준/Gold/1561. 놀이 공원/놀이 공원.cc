#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
long long iResult = 0, temp;

vector<long long> v;

bool Check(long long mid)
{
    temp = M;
    for (long long i = 0; i < M; ++i)
        temp += mid / v[i];

    return temp >= N;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    v.resize(M);
    for (long long i = 0; i < M; ++i)
        cin >> v[i];

    if (N <= M)
    {
        cout << N;
        return 0;
    }

    long long low = 0, high = 60000000004;
    while (low <= high)
    {
        long long mid = (low + high) / (long long)2;
        if (Check(mid))
        {
            iResult = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    temp = M;
    for (long long i = 0; i < M; ++i)
        temp += ((iResult - 1) / v[i]);

    for (long long i = 0; i < M; ++i)
    {
        if (iResult % v[i] == 0)
            temp++;
        if (temp == N)
        {
            cout << i + 1;
            return 0;
        }
    }

    return 0;
}