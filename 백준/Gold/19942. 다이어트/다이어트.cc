#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, mp, mf, ms, mv, iMinValue = INT_MAX;

struct tagFood
{
    int m_mp = 0;
    int m_mf = 0;
    int m_ms = 0;
    int m_mv = 0;
    int m_credit = 0;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> mp >> mf >> ms >> mv;

    vector<tagFood> vFood(N);
    for (int i = 0; i < N; ++i)
        cin >> vFood[i].m_mp >> vFood[i].m_mf >> vFood[i].m_ms >> vFood[i].m_mv >> vFood[i].m_credit;

    vector<int> vResult;

    for (int i = 0; i < (1 << N); ++i)
    {
        vector<int> vIndex;
        tagFood sum_Food;

        for (int j = 0; j < N; ++j)
        {
            if (i & (1 << j))
            {
                sum_Food.m_mp += vFood[j].m_mp;
                sum_Food.m_mf += vFood[j].m_mf;
                sum_Food.m_ms += vFood[j].m_ms;
                sum_Food.m_mv += vFood[j].m_mv;
                sum_Food.m_credit += vFood[j].m_credit;
                vIndex.push_back(j);
            }
        }

        if (sum_Food.m_mp >= mp && sum_Food.m_mf >= mf
            && sum_Food.m_ms >= ms && sum_Food.m_mv >= mv)
        {
            if (sum_Food.m_credit < iMinValue ||
                (sum_Food.m_credit == iMinValue && vIndex < vResult))
            {
                iMinValue = sum_Food.m_credit;
                vResult = vIndex;
            }
        }
    }

    if (vResult.empty())
    {
        cout << -1;
        return 0;
    }

    cout << iMinValue << "\n";

    for (size_t i = 0; i < vResult.size(); ++i)
    {
        cout << vResult[i] + 1;
        if (i < vResult.size() - 1) cout << " ";
    }

    return 0;
}
