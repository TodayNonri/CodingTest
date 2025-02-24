#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string strInput;

void Check() {
    stack<char> st;
    for (int i = 0; i < strInput.size(); ++i)
 {
        if (strInput[i] == '(' || strInput[i] == '[') 
        {
            st.push(strInput[i]);
        }
        else if (strInput[i] == ')') 
        {
            if (!st.empty() && st.top() == '(') 
            {
                st.pop();
            } 
            else
            {
                cout << "no" << "\n";
                return;
            }
        } 
        else if (strInput[i] == ']') 
        {
            if (!st.empty() && st.top() == '[') 
            {
                st.pop();
            }
            else
            {
                cout << "no" << "\n";
                return;
            }
        }
    }

    if (st.empty()) // 수정된 부분: 스택이 비었는지 확인
        cout << "yes" << "\n";
    else
        cout << "no" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        getline(cin, strInput);
        if (strInput == ".")
            break;
        Check();
    }

    return 0;
}