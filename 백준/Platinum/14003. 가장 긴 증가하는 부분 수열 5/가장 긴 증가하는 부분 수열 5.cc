#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;

int N;
int lis[1000004];
pair<int, int> Answer[1000004];
stack<int> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(lis, lis + 1000004, 1000000004);
    cin >> N;

    int iLen = 0;

    for (int i = 0; i < N; ++i)
    {
        int iNum;
        cin >> iNum;
        auto LowerPos = lower_bound(lis, lis + iLen, iNum);
        int iPos = (int)(lower_bound(lis, lis + iLen, iNum) - lis);
        if (*LowerPos == 1000000004) 
            iLen++;

        *LowerPos = iNum;
        Answer[i].first = iPos;
        Answer[i].second = iNum;
    }

    cout << iLen << "\n";

    for (int i = N - 1; i >= 0; --i)
    {
        if (Answer[i].first == iLen - 1)
        {
            st.push(Answer[i].second);
            --iLen;
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
