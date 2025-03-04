#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int N, iResult = 0;
string strInput;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> strInput;

    stack<int> st;
    int iLastNotValue = -1;

    for (int i = 0; i < strInput.size(); ++i)
    {
        if (strInput[i] == '(')
        {
            st.push(i);
        }
        else
        {
            if (!st.empty())
            {
                st.pop();
                if (!st.empty())
                    iResult = max(iResult, i - st.top());
                else
                    iResult = max(iResult, i - iLastNotValue);
            }
            else
                iLastNotValue = i;
        }
    }

    cout << iResult;
    return 0;
}