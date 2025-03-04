#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long N, iResult = 0;
string strInput;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int iInput;
    stack<pair<long long, long long>> st;
    for (int i = 0; i < N; ++i)
    {
        cin >> iInput;
        int iCount = 1;
        while (st.size() && st.top().first <= iInput)
        {
            iResult += st.top().second;
            if (st.top().first == iInput)
                iCount = st.top().second + 1;
            else
                iCount = 1;

            st.pop();
        }
        if (st.size())
            ++iResult;

        st.push({ iInput , iCount});
    }

    cout << iResult;
    return 0;
}
