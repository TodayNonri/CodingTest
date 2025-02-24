#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> vRet;
vector<int> vNum;
stack<int> stNum;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    vRet.resize(N, -1);
    vNum.resize(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> vNum[i];

        while (stNum.size() && vNum[stNum.top()] < vNum[i])
        {
            vRet[stNum.top()] = vNum[i];
            stNum.pop();
        }

        stNum.push(i);
    }

    for (int i = 0; i < N; ++i)
    {
        cout << vRet[i] << " ";
    }

    return 0;
}
